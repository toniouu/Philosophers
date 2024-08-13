NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c utils.c all_errors.c ft_atoi.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re