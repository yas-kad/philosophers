NAME = philo

SRC = srcs/ft_atoi.c srcs/parse.c srcs/time_stamp.c srcs/initial.c \
	srcs/check_death.c srcs/check_eating_num.c srcs/simulation.c \
	srcs/take_left_fork.c srcs/take_right_fork.c \
	srcs/is_eating.c srcs/is_sleeping.c srcs/is_thinking.c \
	srcs/destroy_mutexes.c srcs/philo.c

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
