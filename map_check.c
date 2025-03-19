/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:39 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/19 13:05:18 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void free_game(t_game *game)
{
	free_textures(game);    
	if (game->map)
        free_map(game->map, game->height);
    if (game->win)
		mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }	
    free(game);
}

static char	**copy_map(t_game *game)
{
	int		i;
	char	**map_cpy;

	map_cpy = malloc((game->height * sizeof(char *)) + 1);
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		if (!map_cpy[i])
			return (free_game(game), NULL);
		i++;
	}
	return (map_cpy);
}

static void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 1)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height || map[y][x] == '1'
		|| map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		game->count++;
	if (map[y][x] == 'E')
		game->exit_count = 2;
	map[y][x] = 'F';
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x, y + 1);
}

void	flood_fill_controller(t_game *game)
{
	char	**new_map;
	new_map = copy_map(game);
	if (!new_map)
		return (free_game(game));
	player_position(game);
	game->count = 0;
	flood_fill(game, new_map, game->player_x, game->player_y);
	if (game->exit_count != 2 || game->count != game->collectibles)
	{
		free_map(new_map, game->height);
		free_map(game->map, game->height);
		free(game);
		error_message(4);
	}
	free_map(new_map, game->height);	
}
