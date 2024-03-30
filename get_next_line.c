/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:38 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/30 22:16:12 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_len(char *str);
int		fill_nulls(char *str, int size);

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE];
	char		*tmp_line_buffer;
	char		*line;
	int			read_size;
	int			i;

	i = 0;
	line = (char *)malloc((sizeof(char) * BUFFER_SIZE) + sizeof(char));
	tmp_line_buffer = (char *)malloc((sizeof(char) * BUFFER_SIZE) + sizeof(char));
	while (read(fd, read_buffer, BUFFER_SIZE) > 0 && read_buffer[0] != '\n')
	{
		while (i < BUFFER_SIZE && read_buffer[i] != '\n')
		{
			tmp_line_buffer[i] = read_buffer[i];
			i++;
		}
		tmp_line_buffer = read_buffer[0];
		i++;
		printf("read_buffer: %s\n", read_buffer);
	}
	line[i] = '\0';
	printf("line: %s\n", line);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf("read_buffer: %s\n", read_buffer);
	return (read_buffer);
}

int	fill_nulls(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (i);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	close(fd);
	return (0);
}