#include "get_next_line.h"

char *buffer_to_line(char *line, char *buffer,int last_read);

char	*get_next_line(int fd)
{
    static char	*leftovers[(BUFFER_SIZE * 2) + 1];
    char	*line;
    int		bytes_read;
    char * read_buffer;

    // line = ft_calloc(1, sizeof(char));

    read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (read_buffer == NULL)
        return (NULL);
    

    return (line);
}

char * get_line(char *leftovers, char *line, char* read_buffer, int fd) {
    int bytes_read;
    while (str_len(leftovers) == 0)
    {   
        bytes_read = read(fd, read_buffer, BUFFER_SIZE);
        if (bytes_read == 0){
            if (str_len(line) == 0)
                return (NULL);
        }
        write_line();
        
    }

    if (ft_strchr(read_buffer, '\n') == -1)
    {
        line = ft_strjoin(line, read_buffer);
    }
    else
    {
        line = ft_strjoin(line, read_buffer);
    }

}


int	ft_strchr( char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return i;
		}
		i++;
	}
	if ((char)c == '\0')
	{	
		return i;
	}
	return (-1);
}
