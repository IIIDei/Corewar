##
## EPITECH PROJECT, 2023
## Makefile Dante
## File description:
## EPITECH Project Makefile for DANTE
##

ASM 				=	asm/

COREWAR				=	corewar/

all:
				make -C $(ASM)
				make -C $(COREWAR)

clean:
				make clean -C $(ASM)
				make clean -C $(COREWAR)

fclean:			clean
				make fclean -C $(ASM)
				make fclean -C $(COREWAR)

re:				fclean all

.PHONY:			all clean fclean re
