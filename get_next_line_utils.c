/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:58:08 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/28 15:20:26 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	count;

	if (!dst && !src)
		return (0);
	count = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		count++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, len);
	return (dst);
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
