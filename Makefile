NAME	= push_swap

SRCS	=	\
			instructions_2.c \
			instructions_utils.c \
			instructions.c \
			list_utils.c \
			main.c \
			quicksort.c \
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