/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:27 by lionelulm         #+#    #+#             */
/*   Updated: 2024/03/12 06:52:04 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*concatène plusieurs chaînes de caractères ensemble
puis libère la mémoire*/

char	*joinandfree(char *buffer, char *c)
{
	char	*yes;

	yes = ft_strjoin(buffer, c);
	free(buffer);
	return (yes);
}

/*lecture de la ligne grâce à un file descriptor,
alloue la mémoire nécessaire pour ce qui est lu par
rapport au BUFFER_SIZE donné, retourne le string et
s'arrête s'il trouve un retour à la ligne*/

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		i;

	i = 1;
	if (str == NULL)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
	{
		free(str);
		return (NULL);
	}
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = joinandfree(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

/*créé une nouvelle chaîne de caractères après
avoir trouvé un '\n'. alloue la mémoire nécessaire
puis retourne la ligne.*/

char	*backslashn(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (str == NULL)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}

/*vérifie s'il y a des '\n' pour pouvoir les
copier dans la chaîne de caractères. alloue
cela à la mémoire et renvoie cette nouvelle
chaîne*/

char	*take_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
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
	return (str);
}

/*peut lire un fichier texte ligne par ligne grâce à
la variable static (buffer). une variable static permet
de preserver le résultat précédent et rajouter le
prochain à cela, pouvant concerver les deux.*/

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
	if (buffer == NULL)
		return (NULL);
	ligne = take_line(buffer);
	buffer = backslashn(buffer);
	if (ligne == NULL || ligne[0] == 0)
	{
		free(ligne);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ligne);
}

