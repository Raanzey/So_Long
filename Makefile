NAME = so_long

CFLAGS = cc -Wall -Wextra -Werror

SOURCES = so_long  libft/get_next_line.c 

LIBFT = libft/libft.a



all: $(NAME)


$(NAME): $(SOURCES)
	make -C ./libft -s
	$(CFLAGS) -g -o $(NAME) $(SOURCES) $(LIBFT)

clean:
	make clean -C ./libft -s

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re