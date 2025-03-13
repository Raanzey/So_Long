/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mlx_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:23:28 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/13 14:45:42 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void move_player(t_game *game, int dx, int dy)
{
    if (game->map[game->player_y + dy][game->player_x + dx] != '1')
    {
        if (game->map[game->player_y + dy][game->player_x + dx] == 'C')
        {
            game->collectibles--;
            game->map[game->player_y + dy][game->player_x + dx] = '0';
        }
        else if(game->map[game->player_y + dy][game->player_x + dx] == 'E' && game->collectibles == 0)
        {
            mlx_destroy_window(game->mlx, game->win);
		    error_game(game);
	        write(1, "Error\n", 6);
    	    exit(EXIT_SUCCESS);
        }
        mlx_put_image_to_window(game->mlx, game->win, game->path, game->player_x * 64, game->player_y * 64);
        game->player_x += dx;
        game->player_y += dy;
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_x * 64, game->player_y * 64);
    } 
}

int key_hook(int key_code, t_game *game)
{
    if (key_code == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }
    else if (key_code == 'w')
        move_player(game, 0, -1);
    else if (key_code == 'a')
        move_player(game, -1, 0);
    else if (key_code == 's')
        move_player(game, 0, 1);
    else if (key_code == 'd')
        move_player(game, 1, 0);
    return 0;                
}