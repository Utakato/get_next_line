#include "get_next_line.h"

char * join_storages(char * permanent_storage, char *tmp_storage);
int	ft_strchr( char *s, char c);
char	*ft_substr(char  *s,  int start, int len);
int read_into_buffer(char *buffer, int fd);

char	*get_next_line(int fd)
{
    static char	*permanent_storage;
    char tmp_storage[BUFFER_SIZE + 1];
    char * current_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
        return (NULL);
    while (1) {
        if (read_into_buffer(tmp_storage, fd) == 0)
            break;
        permanent_storage = join_storages(permanent_storage, tmp_storage);
        if (permanent_storage == NULL)
            return (NULL);
        if (ft_strchr(permanent_storage, '\n') != -1)
            break;
    }
    if(str_len(permanent_storage) == 0)
        return (free(permanent_storage) ,(NULL));
    current_line = malloc((ft_strchr(permanent_storage, '\n') + 2) * sizeof(char));
    ft_strlcpy(current_line, permanent_storage, ft_strchr(permanent_storage, '\n') + 1);
    
    ft_strlcpy(tmp_storage, permanent_storage + ft_strchr(permanent_storage, '\n') + 1, str_len(permanent_storage) - ft_strchr(permanent_storage, '\n') + 1);
    
    free(permanent_storage);
    permanent_storage = malloc(str_len(tmp_storage) + 1 * sizeof(char));
    if (permanent_storage == NULL)
        return (NULL);
    ft_strlcpy(permanent_storage, tmp_storage, str_len(tmp_storage) + 1);
    return (current_line);
}


char * join_storages(char * permanent_storage, char *tmp_storage)
{   
    char *tmp;

    if (permanent_storage == NULL)
    {
        permanent_storage = malloc(1 * sizeof(char));
        if (permanent_storage == NULL)
            return (NULL);
        permanent_storage[0] = '\0';
    }
    tmp = ft_strjoin(permanent_storage, tmp_storage);
    if (tmp == NULL)
        return (NULL);
    permanent_storage = tmp;
    return permanent_storage;
}

int read_into_buffer(char *buffer, int fd)
{
    int bytes_read;
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
    {
        return (-1);
    }
    buffer[bytes_read] = '\0';\
    return bytes_read;
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

char	*ft_substr(char  *s,  int start, int len)
{
	char	*small_str;

	if (start > str_len(s))
    {
        small_str = malloc(1 * sizeof(char));
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
