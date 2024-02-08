##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJS =	$(SRC:.c=.o)

NAME	=	my_hunter

#LIB	=	-L lib/my/ -lmy

SFLIB	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

HSRC	=	include/my_hunt.h

CFLAGS	=	-g3

all: create

create: ${OBJS}
		gcc -o $(NAME) $(OBJS) ${SFLIB} -I ${HSRC}

clean:
		rm -f *.o

fclean:clean
		rm -f $(NAME)

re: fclean all
