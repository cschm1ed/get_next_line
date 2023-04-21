/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:58:35 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 19:28:53 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strdup - duplicates a string
 * @str: the input string to be duplicated
 * 
 * Allocates memory and creates a copy of the input string.
 * The memory must be freed by the caller.
 * 
 * Return: a pointer to the newly duplicated string, or NULL if memory allocation failed
 */

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*out;

	len = ft_strlen(str);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	out[len] = 0;
	ft_memcpy(out, str, len);
	return (out);
}

/**
 * ft_strchr - locates the first occurrence of a character in a string
 * @s: the input string to search in
 * @c: the character to search for
 * 
 * Searches the input string for the first occurrence of the character.
 * 
 * Return: a pointer to the first occurrence of the character, or NULL if not found
 */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	char			*str;

	i = 0;
	uc = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)uc)
			return ((char *)str + i);
		i ++;
	}
	if (uc == '\0')
		return ((char *)s + i);
	return (NULL);
}

/**
 * ft_memcpy - copies memory area
 * @dst: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * 
 * Copies 'n' bytes from source memory area to destination memory area.
 * The memory areas must not overlap.
 * 
 * Return: a pointer to the destination memory area
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i ++;
	}
	return (dst);
}

/**
 * ft_strlen - calculates the length of a string
 * @str: the input string to measure
 * 
 * Measures the length of the input string, excluding the terminating null byte.
 * 
 * Return: the length of the string
 */

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

/**
 * ft_strjoin - concatenates two strings
 * @dst: the destination string
 * @src: the source string to append
 * 
 * Allocates memory and creates a new string which is the concatenation of 'dst' and 'src'.
 * The memory of the input strings is freed.
 * The memory of the new string must be freed by the caller.
 * 
 * Return: a pointer to the newly concatenated string, or NULL if memory allocation failed
 */

char	*ft_strjoin(char *dst, char *src)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = -1;
	out = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!out)
		return (free(src), free(dst), NULL);
	if (dst)
	{
		while (dst[i])
		{
			out[i] = dst[i];
			i ++;
		}
	}
	while (j++, src[j])
		out[i + j] = src[j];
	out[i + j] = 0;
	return (free(dst), free(src), out);
}
