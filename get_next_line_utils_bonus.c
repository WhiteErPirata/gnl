/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:40:20 by ccalabro          #+#    #+#             */
/*   Updated: 2024/05/04 23:40:23 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = count * size;
	ptr = malloc(tot);
	if (!ptr)
	{
		return (NULL);
	}
	while (tot--)
		((char *)ptr)[tot] = 0;
	return (ptr);
}

void	*ft_realloc(char *str, int c)
{
	char	*ret;

	ret = (char *)ft_calloc(sizeof(char), ((c * BUFFER_SIZE) + 1));
	if (str && *str)
	{
		ft_strlcat(ret, str);
		free(str);
	}
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (0);
}

void	ft_strlcat(char *dst, char *src)
{
	size_t	c;
	size_t	d;

	c = 0;
	while (dst[c])
		c++;
	d = 0;
	while (src[d] != '\0')
	{
		dst[c] = src[d];
		src[d] = 0;
		c++;
		d++;
	}
	return ;
}

void	ft_strlcat_plus(char *dst, char *src)
{
	size_t	c;
	size_t	d;

	c = 0;
	while (dst[c])
		c++;
	d = 0;
	while (src[d] != '\0')
	{
		dst[c] = src[d];
		src[d] = 0;
		c++;
		d++;
		if (dst[c - 1] == '\n')
			break ;
	}
	ft_strlcat(src, src + d);
	return ;
}
