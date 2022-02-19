NAME = philo

CC = clang

FLAGS    = -Wall -Wextra -Werror -pthread -g

DEL = /bin/rm -f

SRCS =     ./srcs/main.c\
			./srcs/error_arg.c\
			./srcs/init.c\
			./srcs/philo.c\
			./srcs/philo_eat_and_display.c


SRCS_O    = ${SRCS:.c=.o}
all: $(NAME)

LIBC    = ar -rcs

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
		 $(CC) $(FLAGS) $(SRCS_O) -o $(NAME)

fclean: clean
		$(DEL) $(NAME)

clean:
		$(DEL) $(SRCS_O)

re: fclean all
