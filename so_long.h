/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:31:18 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/20 09:12:15 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*path;
	void	*exit;
	void	*collectible;
	void	*player;
	char	**map;
	int		width;
	int		height;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
	int		count;
	int		collectibles;
	int		moves;
}			t_game;

int			read_map(t_game *game, char *file);
int			key_hook(int key_code, t_game *game);
int			ft_strcmp(const char *str1, const char *str2);
int			finish(t_game *game);
int			close_game(t_game *game);
void		free_game(t_game *game);
void		free_textures(t_game *game);
void		ft_putnbr(int n);
void		error_message(int id);
void		file_extension(char *filename, t_game *game);
void		map_cntrl(t_game *game);
void		free_game(t_game *game);
void		free_map(char **map, int height);
void		flood_fill_controller(t_game *game);
void		window(t_game *game);

#endif