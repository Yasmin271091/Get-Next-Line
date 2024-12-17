/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasjimen <yasjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:33 by yasjimen          #+#    #+#             */
/*   Updated: 2024/12/06 14:45:38 by yasjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	handle_buffer(char **stored, char *buffer, int bytes_read)
{
	char	*temp;

	if (bytes_read == -1)
		return (0);
	buffer[bytes_read] = '\0';
	temp = ft_strjoin_free(*stored, buffer);
	if (!temp)
		return (0);
	*stored = temp;
	return (1);
}

char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		bytes_read;

	if (!stored)
		stored = ft_strdup("");
	if (!stored)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stored), NULL);
	bytes_read = 1;
	while (!ft_strchr(stored, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || !handle_buffer(&stored, buffer, bytes_read))
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
		return (free(stored), NULL);
	new_stored = ft_strdup(stored + i + 1);
	free(stored);
	return (new_stored);
}

char	*get_next_line(int fd)
{
	static char	*stored[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored[fd] = read_and_store(fd, stored[fd]);
	if (!stored[fd])
		return (NULL);
	line = extract_line(stored[fd]);
	stored[fd] = update_stored(stored[fd]);
	return (line);
}

/*int	main()
{
	int	fd;
	int	fd2;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	fd2 = open("archivo1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir archivo.txt");
		return (1);
	}
	if (fd2 < 0)
	{
		perror("Error al abrir archivo1.txt");
		close(fd);
		return (1);
	}
	printf("Contenido de archivo.txt:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\nContenido de archivo1.txt:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	close(fd2);
	return (0);
}*/
