/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:58:03 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/29 12:40:02 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_stack(char *stack)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	while (stack[count] && stack[count] != '\n')
		count++;
	if (!stack[count])
	{
		free(stack);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stack) - count + 1));
	if (!str)
		return (0);
	count++;
	i = 0;
	while (stack[count])
		str[i++] = stack[count++];
	str[i] = '\0';
	free(stack);
	return (str);
}

static char	*ft_read_stack(int fd, char stack)
{
	char	*buff;
	int		read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	read = 1;
	while (!ft_strchr(stack, '\n') && read != 0)
	{
		read = read(fd, buff, BUFFER_SIZE);
		if (read == -1)
		{
			free(buff);
			return (0);
		}
		buff[read] = '\0';
		stack = ft_strjoin(stack, buff);
	}
	free(buff);
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stack = ft_read_stack(fd, stack);
	if (!stack)
		return (0);
	line = ft_get_line(stack);
	stack = ft_new_stack(stack);
	return (line);
}
