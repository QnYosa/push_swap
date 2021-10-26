NAME = push_swap

SRCS	= main.c errors.c parsing.c utils.c c_list.c \
	c_list_norm.c leaks.c ope_1.c ope_2.c fill_tab_pop.c \
	print_list.c checking.c pop_trio.c algo_2.c \
	init_and_fill_podium.c chose_pop_.c tab_sort_rev.c \
	 3_arg.c 4_and_more.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

CC		= gcc

RM		= rm -f

all:	${NAME}

$(NAME):	libft ${OBJS}
			${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:
		make -C libft
		@cp libft/*.h ./includes
		@mv libft/libft.a .

bonus:	all

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} libft.a

re:		fclean all

.PHONY:		all clean fclean re bonus libft