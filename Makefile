NAME=so_long

SRCS=  libft/get_next_line.c libft/get_next_line_utils.c so_long.c map_controller.c so_long_utils.c map_check.c game_mlx_controller.c
CFLAGS=-Wall -Wextra -Werror
LIBFT=libft/libft.a
MLX_LIB=minilibx/libmlx.a

MLX_FLAGS=-L minilibx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

$(NAME): $(SRCS) 
	make -C ./libft -s
	make -C ./minilibx -s
	gcc  -o  $(NAME) -g $(SRCS) $(LIBFT) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS)

all: $(NAME)

clean:
	make clean -C ./libft -s
	make clean -C ./minilibx -s

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re