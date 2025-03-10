/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:27:34 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/10 16:55:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "minilibx/mlx.h"
#include<stdio.h>

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
	while ((line = get_next_line(fd)))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
	}
	close(fd);
	game->map = map;
	game->width = ft_strlen(map[0]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game *game;
    game = malloc(sizeof(t_game));
    if (argc == 1)
		exit(EXIT_SUCCESS);
    file_extension(argv[1], game);
	read_map(game, argv[1]);
	map_cntrl(game);
	flood_fill_controller(game);
	window(game);
	mlx_loop(game->mlx);
	return (0);
}
