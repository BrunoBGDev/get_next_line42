/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:58:08 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/29 12:19:24 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[count] != '\0')
	{
		if (s[count] == (char) c)
			return ((char *)&s[count]);
		count++;
	}
	return (0);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	count;

	count = 0;
	if (!dst && !src)
		return (0);
	if (((unsigned char *)src) < ((unsigned char *)dst))
	{
		while (len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (count < len)
		{
			((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		}
	}
	return ((unsigned char *)dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	rst_len;
	char	*join;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	rst_len = s1_len + s2_len + 1;
	join = malloc(sizeof(char) * rst_len);
	if (!join)
		return (0);
	ft_memmove(join, s1, s1_len);
	ft_memmove(join, s1_len, s2_len);
	join[rst_len - 1] = '\0';
	return (join);
}

char	*ft_get_line(char *stack)
{
	int		count;
	char	*str;

	count = 0;
	if (!stack[count])
		return (0);
	while (stack[count] && stack[count] != '\n')
		count++;
	str = (char *)malloc(sizeof(char) * (count + 2));
	if (!str)
		return (0);
	count = 0;
	while (stack[count] && stack[count] != '\n')
	{
		str[count] = stack[count];
		count++;
	}
	if (stack[count] == '\n')
	{
		str[count] = stack[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
