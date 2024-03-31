/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:38 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/31 14:57:40 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_buffer(char *tmp_read, char *read_buffer,
			int *encountered_newline);
char	*add_tmp_to_line(char *line, char *tmp_read);

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*line;
	int			encountered_newline;
	int			bytes_read;
	int reached_eof;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	reached_eof = 0;
	bytes_read = 0;
	encountered_newline = 0;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return ( NULL);
	while (reached_eof != 1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		
		read_buffer[bytes_read] = 0;

		add_tmp_to_line(line, read_buffer);
		if (line == NULL)
			return ( NULL);
		if (encountered_newline == 1)
			break ;
		if (bytes_read < BUFFER_SIZE)
		{
			reached_eof = 1;
			if (bytes_read == 0)
				return (NULL);
		}
	}

	return (line);
}

char	*add_tmp_to_line(char *line, char *tmp_read)
{
	char	*new_line;
	new_line = ft_strjoin(line, tmp_read);
	// printf("new_line: %s \n", new_line);
	if (new_line == NULL)
		return (free(line), free(tmp_read), NULL);
	free(line);
	line = malloc(sizeof(char) * (str_len(new_line) + 1));
	if (line == NULL)
		return (free(new_line), free(tmp_read), NULL);
	ft_strlcpy(line, new_line, str_len(new_line) + 1);
	free(new_line);
	return (line);
}

void	copy_buffer(char *tmp_read, char *read_buffer, int *encountered_newline)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && read_buffer[i] != '\0')
	{
		tmp_read[i] = read_buffer[i];
		if (read_buffer[i] == '\n')
		{
			*encountered_newline = 1;
			break ;
		}
		i++;
	}
}

