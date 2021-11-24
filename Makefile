NAME = philo

SRC = srcs/ft_atoi.c srcs/parse.c srcs/philo.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -o $@ $^

%.o : %.c
	gcc -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
