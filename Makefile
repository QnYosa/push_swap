NAME = push_swap

LIBFT = libft/libft.a

SRCS	= main.c errors.c c_list.c find.c norm_rec_alg.c\
	c_list_norm.c leaks.c ope_1.c ope_2.c cmd_2.c norm_del_u.c\
	print_list.c checking.c is_next.c commands.c\
	tab_sort_rev.c sort_top_non_empty.c norm_stne.c \
	3_arg.c 4_and_more.c 5_arg.c big_algo.c maths_part.c \
	recursive_algo.c stack_b_to_a.c op1.c op2.c \
	big_3.c big_4.c big_5.c opti.c rotate.c  delete.c \
	hundred.c best_m.c utils_hun.c set_moves_h.c str_move.c \
	find_hundred.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra 

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