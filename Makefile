##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

#CFLAGS	=	

SRCDIR	=	src

SRC	=	$(wildcard $(SRCDIR)/*.c) \
		$(wildcard $(SRCDIR)/lib/*.c) \
		$(wildcard $(SRCDIR)/builtins/*.c)  \
		$(wildcard $(SRCDIR)/token/*.c) \
		$(wildcard $(SRCDIR)/lexer/*.c)


OBJ	=	$(SRC:.c=.o)

CFLAGS 	=	-I ./include -g -Wall -W #-ansi

LDFLAGS = -lcriterion -lgcov

NAME	=	42sh

all:	$(NAME) \
	clean
tests_run:
	make -s -C tests

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) #$(LDFLAGS)
	rm $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f ./tests/*.o
	rm -f ./tests/*.gcda
	rm -f ./tests/*.gcno
	rm -f ./src/*.gcda
	rm -f ./src/*.gcno


fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re #bonus
