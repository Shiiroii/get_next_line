/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:27 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/04 15:35:15 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeline(char *buffer, char *c)
{
	char	*yes;

	if (buffer == NULL || c == NULL)
		return (NULL);
	yes = ft_strjoin(buffer, c);
	free(buffer);
	return (yes);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		i;

	if (str == NULL)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1 || i == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	str = freeline(str, buffer);
	if (ft_strchr(buffer, '\n') != NULL || i < BUFFER_SIZE)
	{
		free(buffer);
		return (str);
	}
	return (read_line(fd, str));
}

char	*backslashn(char *buffer)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (buffer[i])
		str[len++] = buffer[i++];
	str[i] = '\0';
	return (str);
}

char	*take_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	result = take_line(buffer);
	if (result == NULL)
		return (NULL);
	buffer = backslashn(buffer);
	if (buffer == NULL)
		return (NULL);
	return (result);
}
