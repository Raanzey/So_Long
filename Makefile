NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Kütüphaneler
LIBFT = library/libft/libft.a
GNL = library/get_next_line/get_next_line.c

# Kaynak dosyalar
SOURCES = so_long.c so_long_utils.c map_controller.c $(GNL)

# Object dosyaları (otomatik oluşturma)
OBJECTS = $(SOURCES:.c=.o)

# Derleme Kuralları
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@make -C ./library/libft
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS)  -o $(NAME)  

# .c -> .o dönüşümü
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Temizlik Kuralları
clean:
	@make clean -C ./library/libft -s
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ./library/libft -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
