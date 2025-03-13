/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:05:46 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/13 14:22:19 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void	is_rectangular(t_game *game);
static void	map_contents(t_game *game);
static void	map_wall(t_game *game);

void	map_cntrl(t_game *game)
{
	is_rectangular(game);
	map_contents(game);
	map_wall(game);
}

static void	is_rectangular(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
		exit(EXIT_FAILURE);
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->width)
		{
			error_game(game);
			write(1, "Error\n", 6);
    		exit(EXIT_FAILURE);
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
		write(1, "Error\n", 6);
		free(game);
		exit(EXIT_FAILURE);
	}	
}

static void	map_contents(t_game *game)
{
	int	i;
	int	j;

	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	i = -1;
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
		}
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| !(game->collectibles >= 1))
	{
		error_game(game);
	    write(1, "Error\n", 6);
    	exit(EXIT_FAILURE);
	}	
}

static void	map_wall(t_game *game)
{
	int i;
	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			error_game(game);
	    	write(1, "Error\n", 6);
    		exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			error_game(game);
	    	write(1, "Error\n", 6);
    		exit(EXIT_FAILURE);
		}
		i++;
	}
}
