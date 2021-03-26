# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 22:59:07 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/03/26 03:25:42 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests.a

CC = gcc
CC_DEBUG_FLAGS = -g

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ../includes
LIBS_PATH = ../libs

LIBFT_PATH = ..
LIBFT = $(LIBFT_PATH)/libft.a

UNITY = $(LIBS_PATH)/Unity/unity.c

SOURCE_FILES = test_something.c
SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

TEST_MAIN = main.c
EXECUTE_TESTS = ./a.out
TEST_GARBAGE = a.out

all: test

test: build_libft $(NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(TEST_MAIN) $(NAME) $(UNITY) $(LIBFT)
	$(EXECUTE_TESTS)

$(NAME): $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	@$(REMOVE) $(NAME)
	@$(REMOVE) $(TEST_GARBAGE)
	@$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all test build_libft re clean fclean
