/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:38 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/31 23:00:31 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*handle_new_line(char *line, char *read_buffer);
int		non_null_char_index(char *str);

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;
	char		*tmp_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (ft_bzero(read_buffer, BUFFER_SIZE), NULL);

	bytes_read = 1;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	while (bytes_read > 0)
	{
		if (non_null_char_index(read_buffer) == BUFFER_SIZE)
		{
			bytes_read = read(fd, read_buffer, BUFFER_SIZE);
			read_buffer[bytes_read] = '\0';
			if (bytes_read < 1)
				break ;
		}
		tmp_line = ft_strjoin(line, read_buffer + non_null_char_index(read_buffer));
		if (tmp_line == NULL)
			return (NULL);
		free(line);
		line = tmp_line;
		if (ft_strchr(line, '\n') != -1)
			break;
	}
	if (line[0] == '\0')
	{
		if (line != NULL)
			free(line);
		return (NULL);
	}
	return (line);
}

// handle new-line case
void	*handle_new_line(char *line, char *read_buffer)
{
	int		i;
	char	*new_line;

	i = ft_strchr(read_buffer, '\n');
	read_buffer = read_buffer + i;
	new_line = malloc(sizeof(char) * (i + 1));
	if (new_line == NULL)
		return (NULL);
	ft_strlcpy(new_line, read_buffer, i + 1);
	line = ft_strjoin(line, new_line);
	return (line);
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

int	non_null_char_index(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i] == '\0')
	{
		i++;
	}
	return (i);
}
