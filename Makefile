NAME = libft $(CLIENT) $(SERVER)
CLIENT = client
SERVER = server
SRCS = client.c server.c
OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./libft -lft

all: $(NAME)

$(CLIENT): client.o
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

$(SERVER): server.o
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

libft:
	make -C libft all

clean:
	rm -f /libft/libft.a
	rm -f $(CLIENT) $(SERVER)

fclean:
	make -C libft fclean
	rm -f $(CLIENT) $(SERVER) $(OBJ)

re: fclean all
	make -C libft re

.PHONY: all libft clean fclean re
