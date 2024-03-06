/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:47 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/06 15:06:09 by lionelulm        ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
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
