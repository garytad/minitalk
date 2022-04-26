NAME = $(CLIENT) $(SERVER)
CLIENT = client
SERVER = server
LIBFT = libft.a
OBJ = $(SRC:.c=.o)
SRC = client.c server.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./libft -lft

all: $(NAME)

$(CLIENT): client.o $(LIBFT)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $< 

$(SERVER): server.o $(LIBFT)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $<

%.o : %.c 
	$(CC) -c $(CFLAGS) $^

$(LIBFT): 
	make -C libft all

clean:
	rm -f /libft/libft.a
	rm -f $(NAME)

fclean:
	make -C libft fclean
	rm -f $(NAME) $(OBJ)

re: fclean all
	make -C libft re

.PHONY: all clean fclean re
