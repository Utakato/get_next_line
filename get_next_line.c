/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:38 by fschipor          #+#    #+#             */
/*   Updated: 2024/04/01 19:26:45 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*handle_new_line(char *line, char *read_buffer);
int		get_next_char(char *str);
int		read_bytes(int fd, char *read_buffer);
int		ft_strchr(char *s, char c);
char	*create_line(char *line, char *read_buffer);

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (ft_bzero(read_buffer, BUFFER_SIZE), NULL);
	bytes_read = 1;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	while (bytes_read > 0 || bytes_read == -2)
	{
		bytes_read = read_bytes(fd, read_buffer);
		if (bytes_read == -1 || bytes_read == 0)
			return (free(line), NULL);
		line = create_line(line, read_buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

int	read_bytes(int fd, char *read_buffer)
{
	int	bytes_read;

	bytes_read = -2;
	if (get_next_char(read_buffer) != BUFFER_SIZE)
		return (bytes_read);
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (ft_bzero(read_buffer, BUFFER_SIZE), -1);
	read_buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*create_line(char *line, char *read_buffer)
{
	if (ft_strchr(read_buffer, '\n') == -1)
	{
		line = ft_strjoin(line, read_buffer);
		ft_bzero(read_buffer, BUFFER_SIZE);
	}
	else
	{
		line = handle_new_line(line, read_buffer + get_next_char(read_buffer));
	}
	return (line);
}

// handle new-line case
void	*handle_new_line(char *line, char *read_buffer)
{
	int		i;
	char	*cut_line;

	i = ft_strchr(read_buffer, '\n');
	cut_line = ft_calloc(i + 1, sizeof(char));
	if (cut_line == NULL)
		return (NULL);
	ft_strlcpy(cut_line, read_buffer, i + 1);
	line = ft_strjoin(line, cut_line);
	ft_bzero(read_buffer, i + 1);
	return (free(cut_line), line);
}

int	get_next_char(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i] == '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (i < str_len(s))
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}