#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_game
{
	void    *mlx;         // MiniLibX bağlantısı
    void    *win;         // Pencere
    char    **map;        // Harita (2D dizi)
    int     width;        // Haritanın genişliği
    int     height;       // Haritanın yüksekliği
    int     exit;
    int     player_count;       
    int     player_x;     // Oyuncunun X konumu
    int     player_y;     // Oyuncunun Y konumu
    int     collectibles; // Toplanabilir öğe sayısı (C)
    int     moves;        // Hamle sayısı
} t_game;
 	
int read_map(t_game *game, char *file);
int	ft_strcmp(const char *str1, const char *str2);
void	file_extension(char *filename);
void	map_check(t_game *game);
void	error(char **map);

#endif