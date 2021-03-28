# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 02:58:38 by lpaulo-m@st       #+#    #+#              #
#    Updated: 2021/03/28 03:27:01 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
CC_DEBUG_FLAGS = -g

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = $(LIBS_PATH)/$(LIBFT)
COPY_LIBFT = cp $(LIBFT_PATH)/libft.a

HEADER_FILE = ft_printf.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES = ft_printf.c ft_vprintf.c \
	\
	pf_parse_flags.c pf_parse_wildcars.c \
	\
	pf_handled_no_conversion.c pf_handled_percent.c pf_handled_s.c \
	pf_handled_c.c pf_handled_int.c pf_handled_u.c \
	pf_handled_hex.c pf_handled_p.c \
	\
	pf_initializers.c \
	\
	pf_percent.c pf_c.c pf_s.c pf_int.c pf_u.c pf_p.c pf_hex.c
SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

EXAMPLE_MAIN = example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

all: $(NAME)

$(NAME): build_libft $(OBJECTS) $(HEADER)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS) 

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(COPY_LIBFT) ./$(NAME)

example: $(NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(EXAMPLE_MAIN) $(NAME)
	$(EXECUTE_EXAMPLE)

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean libft_fclean
	$(REMOVE) $(NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

re: fclean all

norm:
	norminette $(LIBS_PATH)
	@echo ----------------------
	norminette $(INCLUDES_PATH)
	@echo ----------------------
	norminette $(SOURCES_PATH)

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

.PHONY: all build_libft example \
		libft_fclean clean fclean example_clean \
		re norm git gitm
