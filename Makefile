NAME	= push_swap

SRCS	=	\
			instant_sort_3_utils.c \
			instant_sort.c \
			instructions_2.c \
			instructions_utils.c \
			instructions.c \
			list_utils.c \
			main.c \
			quicksort.c \
			sorting_a_2.c \
			sorting_a.c \
			sorting_b_2.c \
			sorting_b.c \
			sorting.c \
			utils_2.c \
			utils.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -I .

%.o :			%.c
				gcc -c -g $(CFLAGS) $< -o $@

$(NAME):		$(OBJS)
				gcc -g $(CFLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re