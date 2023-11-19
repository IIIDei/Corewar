##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## EPITECH Project Makefile for map generator
##

SRC_MAIN 		= 	src/main.c

SRC 			=	src/check_arg.c						\
					src/parsing/file_parsing.c			\
					src/parsing/error_handling/error_handling.c 		\
					src/parsing/error_handling/is_checker.c 			\
					src/parsing/header.c 				\
					src/parsing/struct_filling.c 		\
					src/parsing/utils_parse.c 			\
					src/parsing/prog_size.c 			\
					src/op.c

SRC_UTILS 		=	src/utils/my_put_str.c				\
					src/utils/my_strcmp.c				\
					src/utils/my_str_cat.c				\
					src/utils/folder_into_1d_array.c 	\
					src/utils/len_tab.c   				\
					src/utils/print_tab.c 				\
					src/utils/get_file_size.c 			\
					src/utils/my_str_to_word_array_comma.c 		\
					src/utils/my_strlen.c				\
					src/utils/my_str_to_word_array.c	\
					src/utils/my_file_to_word_array.c	\
					src/utils/my_strcpy.c				\
					src/utils/my_get_nbr.c 				\
					src/utils/my_str_isalphanum.c		\
					src/utils/my_strncpy.c				\
					src/utils/my_itoa.c					\
					src/utils/my_memset.c

SRC_PRINT 		=	src/print/print_help.c				\

SRC_TEST 		=	units_tests/test.c

OBJ 			= 	$(SRC_MAIN:.c=.o) 					\
					$(SRC:.c=.o) 						\
					$(SRC_PRINT:.c=.o) 					\
					$(SRC_UTILS:.c=.o) 					\

OBJ_TEST		= 	$(SRC_TEST:.c=.o)					\
					$(SRC:.c=.o) 						\
					$(SRC_PRINT:.c=.o) 					\
					$(SRC_UTILS:.c=.o) 					\

CFLAGS 			= 	-W -Wall -Wextra -I./include

FLAGS_DEBUG 	= 	-g3

FLAGS_TEST1 	=	--coverage -lcriterion

FLAGS_TEST2		=	--coverage

NAME 			= 	asm

NAME_TEST		= 	unit_tests

$(NAME):			$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:				$(NAME)

debug: 				CFLAGS += $(FLAGS_DEBUG)

debug:				$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS)

clean:
					rm -rf $(OBJ)

clean_test:
					rm -rf $(OBJ_TEST)
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete
					find . -name "*.a" -delete -or -name "*.o" -delete
					find . -name "vgcore.*" -delete
					find . -name "*.cor" -delete
					rm -rf $(NAME_TEST)
					rm -rf $(NAME)

tests_run: 			CFLAGS += $(FLAGS_TEST2)

tests_run: 			$(OBJ_TEST)
					gcc -o $(NAME_TEST) $(OBJ_TEST) $(FLAGS_TEST1)
					rm -rf $(OBJ_TEST)
					./unit_tests --verbose

re:					fclean all

.PHONY:				all debug clean clean_test fclean tests_run re
