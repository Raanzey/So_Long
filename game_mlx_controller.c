#include "minilibx/mlx.h"
#include "so_long.h"

static void draw_map(t_game *game)
{
    int x; 
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);            
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->path, x * 64, y * 64);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y * 64);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * 64, y * 64);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 64, y * 64);
                x++;
        }    
        y++;
    }
}

void window(t_game *game)
{
    int i;
    i = 64;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width * i, game->height * i, "So Long");
    game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &i);
    game->path = mlx_xpm_file_to_image(game->mlx, "textures/path.xpm",  &i, &i);
    game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",  &i, &i);
    game->collectible= mlx_xpm_file_to_image(game->mlx, "textures/gold.xpm",  &i, &i);
    game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",  &i, &i);
    draw_map(game);
}
