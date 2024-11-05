/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:23:55 by liulm             #+#    #+#             */
/*   Updated: 2024/11/05 16:01:11 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	test;
	size_t	i;

	test = nmemb * size;
	if (size && nmemb && (test / nmemb != size))
		return (NULL);
	ptr = malloc(test);
	if (ptr == NULL)
		return (NULL);
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
	char	chr;

	chr = (char)c;
	while (*s)
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
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[len_s1])
	{
		str[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2])
	{
		str[len_s1] = s2[len_s2];
		len_s1++;
		len_s2++;
	}
	str[len_s1] = '\0';
	return (str);
}
