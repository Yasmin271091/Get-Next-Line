/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasjimen <yasjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:52:43 by yasjimen          #+#    #+#             */
/*   Updated: 2024/11/02 19:07:33 by yasjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	copy_content(char *dest, char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while(src[1])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}

}

char	join_buffers(char *existing_buf, char *new_buf)
{
	char	*combined_buf;
	size_t	exist_idx;
	size_t	new_idx;

	if (!existing_buf)
	{
		existing_buf = (char *)malloc(1);
		if (!existing_buf)
			return (NULL);
		existing_buf[0] = '\0';
	}
}
