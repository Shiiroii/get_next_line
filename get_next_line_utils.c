/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:47 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/12 01:52:59 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	test;
	size_t	i;

	test = nmemb * size;
	if (size && nmemb && (test / nmemb != size))
	{
		return (NULL);
	}
	ptr = malloc(test);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < test)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i])
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return (&*(char *)s + i);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		str[i] = s2[i2];
		i++;
		i2++;
	}
	str[i] = '\0';
	return (str);
}
