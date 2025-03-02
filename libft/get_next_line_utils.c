/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:33 by yozlu             #+#    #+#             */
/*   Updated: 2025/03/02 16:04:36 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n);
static void	*ft_memmove(void *dst, const void *src, size_t len);

char	*ft_strjoin_1(char *s1, char const *s2)
{
	char	*size;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen_1(s1);
	s2_len = ft_strlen_1(s2);
	size = malloc(s1_len + s2_len + 1);
	if (size == NULL)
		return (free(size), NULL);
	ft_memmove(size, s1, s1_len);
	ft_memmove(size + s1_len, s2, s2_len);
	size[s1_len + s2_len] = '\0';
	free(s1);
	return (size);
}

size_t	ft_strlen_1(const char *s)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_substr_1(char *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	char	*c;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_1(s) < start)
	{
		c = malloc(1);
		if (!c)
			return (free(c), NULL);
		c[0] = '\0';
		return (free(c), NULL);
	}
	if (len > ft_strlen_1(s) - start)
		len = ft_strlen_1(s) - start;
	new = malloc(len + 1);
	if (new == NULL)
		return (free(new), NULL);
	while (len--)
		new[i++] = s[start++];
	new[i] = 0;
	return ((char *)new);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*s = src;

	ptr = dst;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	else if (dst == src)
		return (dst);
	while (len--)
		ptr[len] = s[len];
	return (dst);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*s = src;

	if (!dst && !src)
		return (NULL);
	ptr = dst;
	while (n--)
		*ptr++ = *s++;
	return (dst);
}
