SRCS	=	ft_atoi.c ft_putchar_fd.c  \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strjoin.c ft_itoa.c \
ft_strlen.c  \
ft_split.c \
ft_strdup.c 


OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

AR		= ar rcs

CFLAGS	= -Wall -Werror -Wextra

CC 		= clang

RM		= rm -f

all:		${NAME}

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS}
	
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re