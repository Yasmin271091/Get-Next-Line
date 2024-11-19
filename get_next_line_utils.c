/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasjimen <yasjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:52:43 by yasjimen          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:27 by yasjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

static void	ft_copy_str(char *dest, const char *src, size_t len)
{
    size_t	i;
	
	i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
}

char	*ft_strjoin_free(char *s1, char *s2)
{
    char *result;
    size_t	len1;
    size_t	len2;
	
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
    result = (char *)malloc(len1 + len2 + 1);
    if (!result)
		return (NULL);
    if (s1)
    {
        ft_copy_str(result, s1, len1);
        free(s1);
    }
    if (s2)
    {
        ft_copy_str(result + len1, s2, len2);
    }
    result[len1 + len2] = '\0';
    return (result);
}

char	*ft_strdup(const char *s)
{
    size_t	len;
    char	*dup;
	size_t	i;
	
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t	i;
	
	if (!s || start >= ft_strlen(s))
		return (NULL);
		
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
