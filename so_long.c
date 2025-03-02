/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:27:34 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/02 16:12:00 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
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
	printf("agfk\n");
    line = get_next_line(fd);
	printf("agfk\n");
	
	while (line)
	{
		i++;
		free(line);
        line = get_next_line(fd);
	}
	printf("agfk\n");
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
		map[i++] = line;
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
    file_extension(argv[1]);
	read_map(game, argv[1]);
    map_check(game);
	return (0);
}
