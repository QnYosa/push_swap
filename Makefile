NAME = push_swap
NAME_BONUS = checker

LIBFT = libft/libft.a

SRCS_SHARED = maestro.c errors.c c_list.c find.c norm_rec_alg.c\
	c_list_norm.c leaks.c ope_1.c ope_2.c cmd_2.c \
	print_list.c checking.c is_next.c commands.c\
	tab_sort_rev.c sort_top_non_empty.c norm_stne.c \
	3_arg.c 4_and_more.c 5_arg.c big_algo.c maths_part.c \
	recursive_algo.c stack_b_to_a.c op1.c op2.c \
	big_3.c big_4.c big_5.c opti.c rotate.c  delete.c \
	norm_del_u.c
SRCS	= main.c $(SRCS_SHARED)
SRCS_B	= bonus/main.c bonus/tester.c bonus/get_next_line.c bonus/get_next_line_utils.c \
	 $(SRCS_SHARED)

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

CC		= clang

RM		= rm -f

all:	$(NAME)
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_B)
	make -C libft
	@cp libft/*.h ./includes
	@mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS_B) libft.a -o $(NAME_BONUS)

$(NAME):	${OBJS}
			make -C libft
			@cp libft/*.h ./includes
			@mv libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
		make -C libft
		@cp libft/*.h ./includes
		@mv libft/libft.a .

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) libft.a

re:		fclean all

.PHONY:		all clean fclean re bonus libft bonus