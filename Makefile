NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c \
		validation_parsing/parsing.c \
		validation_parsing/validation.c \
		stack.c \
		operation/swap.c \
		operation/push.c \
		operation/rotate.c \
		operation/reverse_rotate.c \
		sorting/sort_small.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re