NAME = philo

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c philo.c utils.c all_errors.c ft_atoi.c routine.c time.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;32mCompilation finished ... !" 
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1m\nW E L C O M E   T O   M Y   P H I L O   P R O G R A M M E !\n \033[0m"
	@echo "\033[0;33m./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat\033[0;34m(optional)\033[0;33m]\033[0m"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re