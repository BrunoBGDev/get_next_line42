/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:58:08 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/28 12:26:47 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
