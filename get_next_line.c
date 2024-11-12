/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasjimen <yasjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:33 by yasjimen          #+#    #+#             */
/*   Updated: 2024/11/12 17:05:40 by yasjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_store(int fd, char *stored);
static char	*extract_line(char *stored);
static char	*update_stored(char *stored);

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = read_and_store(fd, stored);
	if (!stored)
		return (NULL);
	line = extract_line(stored);
	stored = update_stored(stored);
	return (line);
}

static char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stored, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stored = ft_strjoin_free(stored, buffer);
		if (!stored)
			break ;
	}
	free(buffer);
	return (stored);
}

static char	*extract_line(char *stored)
{
	char	*line;
	int		i;

	if (!stored || stored[0] == '\0')
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	line = ft_substr(stored, 0, i + (stored[i] == '\n'));
	return (line);
}

static char	*update_stored(char *stored)
{
	char	*new_stored;
	int		i;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	new_stored = ft_strdup(stored + i + 1);
	free(stored);
	return (new_stored);
}
