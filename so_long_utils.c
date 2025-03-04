/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:33 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/04 15:59:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	error_map(char **map)
{
	int i;
	i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

void	error_game(t_game *game)
{
	int i;
	
    if (game && game->map)
    {
        i = 0;
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }
    if (game)
        free(game);
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str2 == '0')
		str2++;
	while (*str1 == '0')
		str1++;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}