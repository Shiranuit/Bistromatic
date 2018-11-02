##
## EPITECH PROJECT, 2018
## Make
## File description:
## Make
##

NAME	=	calc

SRC	=	./src/main.c	\
		./lib/*.c	\
		./src/evalexpr/*.c	\
		./src/operators/infadd_sub/*.c	\
		./src/operators/mulinf/*.c	\
        ./src/operators/div_mod_inf/divinf.c \
		./src/operators/*.c	\
		./src/evalexpr/exceptions/*.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -I./include -o $(NAME) -g

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
