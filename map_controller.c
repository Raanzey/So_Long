/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:05:46 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/19 13:20:31 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_rectangular(t_game *game);
static void	map_contents(t_game *game, int i, int j);
static void	map_wall(t_game *game);

void	map_cntrl(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->path = NULL;
	game->exit = NULL;
	game->collectible = NULL;
	game->player = NULL;
	is_rectangular(game);
	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	map_contents(game, -1, 0);
	map_wall(game);
}

static void	is_rectangular(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
	{
		free_game(game);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->width)
		{
			free_game(game);
			error_message(0);
		}
		i++;
	}
}

void	file_extension(char *file_name, t_game *game)
{
	char	*str;

	str = ft_strrchr(file_name, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		free_game(game);
		error_message(1);
	}
}

static void	map_contents(t_game *game, int i, int j)
{
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
			{
				free_game(game);
				error_message(2);
			}
		}
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| !(game->collectibles >= 1))
	{
		free_game(game);
		error_message(2);
	}
}

static void	map_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			free_game(game);
			error_message(3);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			free_game(game);
			error_message(3);
		}
		i++;
	}
}
