NAME = minitalk

CC = cc
CFLAGS = 
SRC = client.c server.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o client client.o $(LIBFT)
	$(CC) $(CFLAGS) -o server server.o $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f client server

re: fclean all

run: all
	@echo "Starting server..."
	./server &
	@echo "Starting client..."
	./client 12345 "Hello, Server!"

push : 
	git add .
	git commit -m "To infinity and beyond"
	git push

.PHONY : all clean fclean re 	

