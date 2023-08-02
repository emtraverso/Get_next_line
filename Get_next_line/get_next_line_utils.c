/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:45:32 by etravers          #+#    #+#             */
/*   Updated: 2022/10/25 15:45:49 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stack, char *buff)
{
	size_t	i;
	size_t	k;
	char	*str;

	k = 0;
	i = -1;
	if (!stack)
	{
		stack = (char *)malloc(1 * sizeof(char));
		stack[0] = '\0';
	}
	if (!stack || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stack) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	if (stack)
		while (stack[++i] != '\0')
			str[i] = stack[i];
	while (buff[k] != '\0')
		str[i++] = buff[k++];
	str[ft_strlen(stack) + ft_strlen(buff)] = '\0';
	free(stack);
	return (str);
}
