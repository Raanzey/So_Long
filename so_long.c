/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:27:34 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/17 16:22:34 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	finish(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(EXIT_SUCCESS);
}

void free_textures(t_game *game)
{
    if (game->player)
        mlx_destroy_image(game->mlx, game->player);
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if (game->exit)
        mlx_destroy_image(game->mlx, game->exit);
    if (game->collectible)
        mlx_destroy_image(game->mlx, game->collectible);
    if (game->path)
        mlx_destroy_image(game->mlx, game->path);
}

int	map_height(char *file)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	read_map(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;
	
	game->height = map_height(file);
	map = malloc((map_height(file) + 1) * sizeof(char *));
	if (!map)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	game->map = map;
	game->width = ft_strlen(map[0]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc == 1)
		exit(EXIT_SUCCESS);
	file_extension(argv[1], game);
	read_map(game, argv[1]);
	map_cntrl(game);
	game->moves = 0;
	flood_fill_controller(game);
	window(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
