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
	static char	read_buffer[BUFFER_SIZE];
	char		*tmp_read;
	char		*line;
	int			encountered_newline;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = 0;
	encountered_newline = 0;
	tmp_read = ft_calloc((BUFFER_SIZE), sizeof(char));
	if (tmp_read == NULL)
		return ((NULL));
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	if (line == NULL)
		return (free(tmp_read), NULL);
	while (bytes_read != -1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			bytes_read = -1;
			break ;
		}
		copy_buffer(tmp_read, read_buffer, &encountered_newline);
		
		add_tmp_to_line(line, tmp_read);
		if (line == NULL)
			return (free(tmp_read), NULL);
		if (encountered_newline == 1)
			break ;
	}
	if (tmp_read[0] == 0)
	{
		return (free(tmp_read), free(line), NULL);
	}
	free(tmp_read);
	return (line);
}

char	*add_tmp_to_line(char *line, char *tmp_read)
{
	char	*new_line;
	new_line = ft_strjoin(line, tmp_read);
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
	while (i < BUFFER_SIZE)
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

