#ifndef SO_LONG_H
# define SO_LONG_H

# include "../So_long/libft/libft.h"
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
    int     player_x;     // Oyuncunun X konumu
    int     player_y;     // Oyuncunun Y konumu
    int     collectibles; // Toplanabilir öğe sayısı (C)
    int     collected;    // Toplanan öğe sayısı
    int     moves;        // Hamle sayısı
} t_game;
 	


#endif