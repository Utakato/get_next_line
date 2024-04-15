/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:48 by fschipor          #+#    #+#             */
/*   Updated: 2024/04/01 19:22:28 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (j < BUFFER_SIZE && s2[j] != '\0' && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = s2[j];
	if (j < BUFFER_SIZE && str[i] != '\0')
		str[i + 1] = '\0';
	ft_bzero(s2, j + 1); // mb issue?
	return (free(s1), str);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = str_len((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize && src[i] != '\0' )
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (src_len);
}

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)0;
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

