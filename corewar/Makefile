##
## EPITECH PROJECT, 2023
## B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
## File description:
## makefile for lib
##

PREFIX 			=	src/

INSTRUC_PREFIX 	= 	src/instructions/

LIB_PREFIX 		=	src/tools/lib/

PRINTF_PREFIX 	= 	src/tools/printf/

FILES 			=	main.c										\
					op.c										\
					free.c										\
					algo/program_loop.c							\
					algo/game_end.c								\
					algo/set_cycle.c							\
					check/check_args.c							\
					check/check_file.c							\
					check/dump_flag.c							\
					utils/my_put_str.c							\
					utils/my_memcpy.c							\
					utils/open_file.c							\
					utils/my_get_nbr.c							\
					init/init_core.c							\
					init/init_instruction.c						\
					init/init_arena.c							\
					champions/get_nb_champ.c					\
					champions/init_champions.c					\
					champions/load_champions.c					\
					champions/read_champions.c					\
					print/print_help.c							\
					print/display.c								\

INSTRUCTIONS 	=	add_sub.c									\
					live.c										\
					read_instruction.c							\
					exec_instruction.c							\

LIB				=	my_putchar.c								\
					my_putstr.c									\
					my_put_error.c								\
					my_put_nbr.c								\
					my_strlen.c									\
					my_get_nbr.c								\
					my_strcmp.c									\
					my_strncmp.c								\
					my_strcpy.c									\
					my_strncpy.c								\
					my_strdup.c									\
					my_strcat.c									\
					array_utils.c								\
					str_utils.c									\
					my_str_isalpha.c

PRINTF 			=	int_conv.c									\
					my_printf.c

SRC				=	$(addprefix $(LIB_PREFIX), $(LIB))			\
					$(addprefix $(INSTRUC_PREFIX), $(INSTRUCTIONS))	\
					$(addprefix $(PRINTF_PREFIX), $(PRINTF))	\
					$(addprefix $(PREFIX), $(FILES))

OBJ				=	$(SRC:.c=.o)

NAME			=	corewar

CFLAGS 			= 	-W -Wall -Wextra -ggdb3

CPPFLAGS		=	-I./include/

all:				$(NAME)

$(NAME):			$(OBJ)
					gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
					rm -rf $(OBJ)

fclean:				clean
					rm -rf $(NAME)

re:					clean all

.PHONY: 			re fclean clean all
