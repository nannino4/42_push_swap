NAME		= push_swap

BONUS_NAME	= checker

SRCS		=	\
				push_swap_srcs/instant_sort_3_utils.c \
				push_swap_srcs/instant_sort.c \
				push_swap_srcs/instructions_2.c \
				push_swap_srcs/instructions_utils.c \
				push_swap_srcs/instructions.c \
				push_swap_srcs/list_utils.c \
				push_swap_srcs/main.c \
				push_swap_srcs/quicksort.c \
				push_swap_srcs/sorting_a_2.c \
				push_swap_srcs/sorting_a.c \
				push_swap_srcs/sorting_b_2.c \
				push_swap_srcs/sorting_b.c \
				push_swap_srcs/sorting.c \
				push_swap_srcs/utils_2.c \
				push_swap_srcs/utils.c \

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	=	\
				checker_srcs/gnl_utils.c \
				checker_srcs/gnl.c \
				checker_srcs/instructions_2.c \
				checker_srcs/instructions_utils.c \
				checker_srcs/instructions.c \
				checker_srcs/list_utils.c \
				checker_srcs/main.c \
				checker_srcs/utils.c \
				checker_srcs/utils_2.c \

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror -I ./include

%.o :		%.c
			gcc -c -g $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			gcc -g $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

bonus:		$(NAME) $(BONUS_OBJS)
			gcc -g $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -f $(NAME) $(BONUS_NAME)

re:			fclean all

.PHONY:		all clean fclean re