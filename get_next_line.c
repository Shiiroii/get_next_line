/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:19:04 by liulm             #+#    #+#             */
/*   Updated: 2024/11/07 14:01:19 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char	*str)
{
	char	*buffer;
	char	*joined_str;
	int		i;

	i = 1;
	if (str == NULL)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (free(str), NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		joined_str = ft_strjoin(str, buffer);
		free(str);
		str = joined_str;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

static char	*backslashn_verif(char *str)
{
	char	*temp_str;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	temp_str = ft_calloc(i + 1, sizeof(char));
	if (temp_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp_str[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		temp_str[i++] = '\n';
	return (temp_str);
}

static char	*next_line(char *str)
{
	char	*temp_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp_str = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (temp_str == NULL)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str[i])
		temp_str[j++] = str[i++];
	free(str);
	return (temp_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_line(fd, str);
	if (str == NULL)
		return (NULL);
	line = backslashn_verif(str);
	str = next_line(str);
	if (line == NULL || line[0] == 0)
	{
		free(line);
		free(str);
		str = NULL;
		return (NULL);
	}
	return (line);
}
