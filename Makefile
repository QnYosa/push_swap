NAME = push_swap

LIBFT = libft/libft.a

SRCS	= main.c errors.c parsing.c utils.c c_list.c \
	c_list_norm.c leaks.c ope_1.c ope_2.c \
	print_list.c checking.c is_next.c\
	tab_sort_rev.c sort_top_non_empty.c \
	3_arg.c 4_and_more.c 5_arg.c big_algo.c maths_part.c \
	recursive_algo.c stack_b_to_a.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -g

CC		= clang

RM		= rm -f

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
		make -C libft
		@cp libft/*.h ./includes
		@mv libft/libft.a .

bonus:	all

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) libft.a

re:		fclean all

.PHONY:		all clean fclean re bonus libft