/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:33 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/20 09:12:48 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	error_message(int id)
{
	if (id == 0)
		write(1, "Error: Invalid map format!\n", 27);
	else if (id == 1)
		write(1, "Error: Invalid file extension!\n", 31);
	else if (id == 2)
		write(1, "Error: Invalid map contents!\n", 29);
	else if (id == 3)
		write(1, "Error: Map is not enclosed by walls!\n", 37);
	else if (id == 4)
		write(1, "Error: Unattainable target!\n", 29);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
