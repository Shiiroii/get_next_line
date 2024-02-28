/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:47 by lionelulm         #+#    #+#             */
/*   Updated: 2024/02/23 23:09:34 by lionelulm        ###   ########.fr       */
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
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	i = 0;
	while (i < s1l)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s1l + s2l)
	{
		str[i] = s2[i - s1l];
		i++;
	}
	str[i] = '\0';
	return (str);
}
