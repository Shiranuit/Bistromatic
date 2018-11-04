##
## EPITECH PROJECT, 2018
## Make
## File description:
## Make
##

NAME	=	calc

SRC	=	./lib/*.c	\
		./src/evalexpr/*.c	\
		./src/operators/infadd_sub/*.c	\
		./src/operators/mulinf/*.c	\
        ./src/operators/div_mod_inf/*.c \
		./src/operators/*.c	\
		./src/evalexpr/exceptions/*.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ./src/main.c $(SRC) -I./include -o $(NAME) -g

test: fclean
	gcc -Wall -Wextra -Werror ./tests/*.c ./tests/unit_tests/*.c $(SRC) -I./include -I./tests/unit_tests/include -I./tests/include -o $(NAME) -g

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
