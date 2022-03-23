# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/03/22 23:17:10 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

MINIRT_HEADER = $(INCLUDES_PATH)/minirt.h
MINIRT_ARCHIVE = $(ARCHIVES_PATH)/minirt.a

CC = gcc
CC_STRICT = $(CC) $(CCF_STRICT) $(CCF_OPTIMIZATION)

CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g -fsanitize=leak

CCF_LIBS = -lm -lbsd -lmlx -lXext -lX11

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp
OPEN_IMAGE = ffplay

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives
BITMAPS_PATH = ./bitmaps

SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)

OBJECTS = $(patsubst $(SOURCES_PATH)/%.c, $(OBJECTS_PATH)/%.o, $(SOURCES))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

ARCHIVES = $(MINIRT_ARCHIVE) $(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE)

################################################################################
# REQUIRED
################################################################################

REQUIRED_MAIN = ./main.c

all: $(NAME)

$(NAME): $(MINIRT_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

$(MINIRT_ARCHIVE): initialize $(MINIRT_HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(MINIRT_ARCHIVE) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

re: fclean all

################################################################################
# INITIALIZE
################################################################################

initialize: make_dirs build_libs

make_dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) $(OBJECT_DIRECTORIES) $(BITMAPS_PATH)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@

$(BITMAPS_PATH):
	$(SAFE_MAKEDIR) $@

build_libs: build_libft build_ft_libbmp

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(MINIRT_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

tclean: clean_libs fclean example_clean vglog_clean

################################################################################
# RUN
################################################################################

run: re
	./$(NAME) scenes/bad_cam_look_at.rt
	$(OPEN_IMAGE) bitmaps/camera_1.bmp

################################################################################
# LIBS
################################################################################

LIBS_PATH = ./libs

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)
LIBFT_HEADER = $(LIBFT_PATH)/includes/libft.h

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(LIBFT_ARCHIVE)
	$(COPY) $(LIBFT_HEADER) $(INCLUDES_PATH)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean
	$(REMOVE) $(LIBFT_ARCHIVE)

FT_LIBBMP = ft_libbmp.a
FT_LIBBMP_PATH = $(LIBS_PATH)/ft_libbmp
FT_LIBBMP_ARCHIVE = $(ARCHIVES_PATH)/$(FT_LIBBMP)
FT_LIBBMP_HEADER = $(FT_LIBBMP_PATH)/includes/ft_libbmp.h

build_ft_libbmp:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH) all
	$(COPY) $(FT_LIBBMP_PATH)/$(FT_LIBBMP) $(FT_LIBBMP_ARCHIVE)
	$(COPY) $(FT_LIBBMP_HEADER) $(INCLUDES_PATH)

ft_libbmp_clean:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH) fclean
	$(REMOVE) $(FT_LIBBMP_ARCHIVE)

clean_libs: libft_clean ft_libbmp_clean

################################################################################
# EXAMPLE
################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
IMAGE_NAME = hello.bmp
EXECUTE_EXAMPLE = ./a.out $(IMAGE_NAME)
EXAMPLE_GARBAGE = a.out a.out.dSYM $(IMAGE_NAME)

build_example: $(MINIRT_ARCHIVE)
	$(CC) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(EXAMPLE_MAIN) \
		$(ARCHIVES) \
		$(CCF_LIBS)

example: build_example
	$(EXECUTE_EXAMPLE)
	$(OPEN_IMAGE) $(IMAGE_NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes
VALGRIND_LOG = valgrind_leaks.log
VALGRIND_LOG_FLAGS = --log-file=$(VALGRIND_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-origins=yes \
	--verbose
VALGRIND_TARGET = ./$(NAME) bitmaps/camera_1.bmp

vg: re vg_build
	$(VALGRIND) $(VALGRIND_FLAGS) $(VALGRIND_TARGET)
	$(OPEN_IMAGE) bitmaps/camera_1.bmp

vglog: re vg_build
	$(VALGRIND) $(VALGRIND_LOG_FLAGS) $(VALGRIND_TARGET)
	$(OPEN_IMAGE) bitmaps/camera_1.bmp

vg_build: $(MINIRT_ARCHIVE)
	$(CC_STRICT) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VALGRIND_LOG)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(REQUIRED_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(REQUIRED_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

################################################################################
# PHONY
################################################################################

.PHONY: \
	all re \
	initialize make_dirs build_libs \
\
	clean fclean tclean clean_libs \
\
	run \
\
	build_libft libft_clean \
	build_ft_libbmp ft_libbmp_clean \
\
	build_example example example_clean \
	vg vglog vg_build vglog_clean \
\
	norm git gitm

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
