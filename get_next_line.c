/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasjimen <yasjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:33 by yasjimen          #+#    #+#             */
/*   Updated: 2024/11/19 20:19:34 by yasjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_buffer(char **stored, char *buffer, int bytes_read)
{
	char	*temp;

	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes_read] = '\0';
	temp = ft_strjoin_free(*stored, buffer);
	if (!temp)
	{
		free(buffer);
		return (0);
	}
	*stored = temp;
	return (1);
}

char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		bytes_read;
	
	buffer = NULL;
	if (!stored)
		stored = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stored), NULL);
	bytes_read = 1;
	while (!ft_strchr(stored, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!handle_buffer(&stored, buffer, bytes_read))
		{
			free(buffer);
			free(stored);
			return (NULL);
		}
	}
	free(buffer);
	return (stored);
}

char	*extract_line(char *stored)
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

char	*update_stored(char *stored)
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
	if (!stored || stored[0] == '\0')
	{
		free(stored);
		stored = NULL;
	}
	return (line);
}
/*#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    char *line;

    fd = open("archivo.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}*/
