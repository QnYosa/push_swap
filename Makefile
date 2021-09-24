NAME = push_swap

SRCS	= main.c errors.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall  -Werror -Wextra

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