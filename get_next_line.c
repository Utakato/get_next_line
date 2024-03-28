#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char * read_buffer[BUFFER_SIZE];
    int read_size;

    // fill_nulls(read_buffer, BUFFER_SIZE);
    read_size = str_len(read_buffer);

    if (read_size < BUFFER_SIZE)
    {
        // it means we reached eof and we won't have to read anymore
    }
    else
    {
        // we need to read more
        read_size = read(fd, read_buffer, BUFFER_SIZE);
    }
    
    
}

int fill_nulls(char* str, int size)
{
    int i = 0;
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    return i;
}


int str_len(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
