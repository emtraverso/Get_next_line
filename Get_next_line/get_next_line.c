/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:44:16 by etravers          #+#    #+#             */
/*   Updated: 2022/10/25 15:45:17 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_linea(char *stack)
{
	int		i;
	char	*str;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		str[i] = stack[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_stack_copia(char *stack)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (stack[i])
		str[k++] = stack[i++];
	str[k] = '\0';
	free(stack);
	return (str);
}

char	*ft_read(int fd, char *stack)
{
	char	*buff;
	int		bytes_letti;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_letti = 1;
	while (!ft_strchr(stack, '\n') && bytes_letti != 0)
	{
		bytes_letti = read(fd, buff, BUFFER_SIZE);
		if (bytes_letti == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_letti] = '\0';
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
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);
	line = ft_linea(stack);
	stack = ft_stack_copia(stack);
	return (line);
}
