.SUFFIXES : .c .o

NAME=webserver
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g3 -fsanitize=address
LIBFT=./libft/libft.a

SRCS=webserver.c handle_request.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C ./libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
