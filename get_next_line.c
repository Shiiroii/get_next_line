/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:27 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/06 17:16:45 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	char	*str2;
	int		i;
	int		len;

	if (str == NULL)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	len = ft_strlen(str);
	str2 = ft_calloc(len + i + 1, sizeof(char));
	if (i == -1 || str2 == NULL)
	{
		free(buffer);
		return (NULL);
	}
	else if (i == 0)
	{
		free(buffer);

		return (ft_calloc(1, 1));
	}
	buffer[i] = '\0';
	if (str != NULL)
		ft_strlcpy(str2, str, len + 1);
	ft_strlcpy(str2 + len, buffer, i + 1);
	free(buffer);
	free(str);
	return (str2);
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

// char	*take_line(char *buffer)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	str = ft_calloc(i + 1, sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		str[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] && buffer[i] == '\n')
// 		str[i++] = '\n';
// 	str[i] = '\0';
// 	return (str);
// }

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	result = read_line(fd, buffer);
	if (!result)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	else if (result[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		free(result);
		return (NULL);
	}
	return (result);
}
