/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:27 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/11 03:37:26 by lionelulm        ###   ########.fr       */
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
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i > 0 || ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = freeline(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*backslashn(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, buffer, i + 1);
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
		return (NULL);
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

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*result;

// 	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) < 0)
// 	{
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	buffer = read_line(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	result = take_line(buffer);
// 	buffer = backslashn(buffer);
// 	if (!result || result[0] == 0)
// 	{
// 		free(result);
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	free(buffer);
// 	return (result);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	ligne = take_line(buffer);
	buffer = backslashn(buffer);
	if (!ligne || ligne[0] == 0)
	{
		free(ligne);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ligne);
}
