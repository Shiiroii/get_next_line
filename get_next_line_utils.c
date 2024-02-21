/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:47 by lionelulm         #+#    #+#             */
/*   Updated: 2024/02/21 15:37:41 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t nb)
{
	size_t	i;
	char	*strchar;

	i = 0;
	strchar = (char *)str;
	while (i < nb)
	{
		strchar[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	test;

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
	ft_bzero(ptr, (test));
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != '\0')
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1l;
	size_t	s2l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	s1l = 0;
	s2l = 0;
	if (str == NULL)
		return (NULL);
	while (s1[s1l])
	{
		str[s1l] = s1[s1l];
		s1l++;
	}
	while (s2[s2l])
	{
		str[s1l] = s2[s2l];
		s1l++;
		s2l++;
	}
	str[s1l] = '\0';
	return (str);
}

char	*freeline(char *buffer, char *c)
{
	char	*yes;

	yes = ft_strjoin(buffer, c);
	free(buffer);
	return(yes);
}

char	*backslashn(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		i++;
		str[i] = '\n';
	return (str);
}
