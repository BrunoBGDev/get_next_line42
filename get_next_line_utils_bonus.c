/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:58:08 by bbraga            #+#    #+#             */
/*   Updated: 2022/07/01 20:58:51 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
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

char	*ft_strjoin(char *stack, char *buff)
{
	size_t	count;
	size_t	i;
	char	*join;

	if (!stack)
	{
		stack = (char *)malloc(1 * sizeof(char));
		stack[0] = '\0';
	}
	if (!stack || !buff)
		return (0);
	join = malloc(sizeof(char) * ((ft_strlen(stack) + ft_strlen(buff)) + 1));
	if (join == NULL)
		return (0);
	count = -1;
	i = 0;
	if (stack)
		while (stack[++count] != '\0')
				join[count] = stack[count];
	while (buff[i] != '\0')
		join[count++] = buff[i++];
	join[ft_strlen(stack) + ft_strlen(buff)] = '\0';
	free(stack);
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
