/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:38 by fschipor          #+#    #+#             */
/*   Updated: 2024/04/03 22:35:39 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *s1);
char	*fill_buffer(int fd, char *line);
char	*get_line(char *line);

char	*get_next_line(int fd)
{
	static char	*line;
	char		*current_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char));
	if (line == NULL)
		return (NULL);
	line = fill_buffer(fd, line);
	if (line == NULL)
		return (NULL);
	current_line = get_line(line);
	if (current_line == NULL)
		return (free(line),NULL);
	return (current_line);
}

char	*fill_buffer(int fd, char *last_line)
{
	char	*buffer;

	while (1)
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (read(fd, buffer, BUFFER_SIZE) == 0)
		{
			if (str_len(last_line) == 0)
				return (free(last_line), free(buffer), NULL);
			else
				return (free(buffer), (last_line));
		}

		buffer[BUFFER_SIZE] = '\0';
		if (str_len(last_line) == 0){
			last_line = ft_strdup(buffer);
			free(buffer);
		}
		else
			last_line = ft_strjoin(last_line, buffer);
		if (last_line == NULL)
			return ( NULL);
		if (ft_strchr(last_line, '\n') != -1)
			return ( (last_line));
	}
}

char	*get_line(char *line)
{
	int		newline_i;
	char	*temp;
	char	*rest;

	newline_i = ft_strchr(line, '\n');
	if (newline_i == -1)
		return (line);
	if (line == NULL)
		return (free(line), NULL);
	temp = ft_substr(line, 0, newline_i + 1);
	if (temp == NULL)
		return (free(line), NULL);
	rest = ft_substr(line, newline_i + 1, str_len(line) - newline_i - 1);
	free(line);
	line = ft_strdup(rest);
	free(rest);
	return (temp);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = str_len(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (i < str_len(s))
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int len)
{
	char *small_str;

	if (start > str_len(s))
	{
		small_str = (char *)malloc(1 * sizeof(char));
		if (small_str == NULL)
			return (NULL);
		small_str[0] = '\0';
		return (small_str);
	}
	if (len > str_len(s + start))
		len = str_len(s + start);
	small_str = (char *)malloc((len + 1) * sizeof(char));
	if (small_str == NULL)
		return (NULL);
	ft_strlcpy(small_str, s + start, len + 1);
	return (small_str);
}