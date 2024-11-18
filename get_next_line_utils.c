/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:52:43 by yasjimen          #+#    #+#             */
/*   Updated: 2024/11/18 21:16:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

static void ft_copy_str(char *dest, const char *src, size_t len)
{
    size_t i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
}

char *ft_strjoin_free(char *s1, char *s2)
{
    char *result;
    size_t len1 = 0;
    size_t len2 = 0;

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

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
    
    size_t i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    if (!s || start >= ft_strlen(s))
        return (NULL);

    char *substr = (char *)malloc(len + 1);
    if (!substr)
        return (NULL);

    size_t i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
