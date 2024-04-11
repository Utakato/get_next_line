#include "../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	char	*test;

	test = "tests/test0";
	fd = open(test, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line: %s \n", line);
	}
	close(fd);
	return (0);
}
// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int i;
// 	char *test = "tests/test0";

// 	i = 0;

// 	while (i < 3)
// 	{
// 		fd = open(test, O_RDONLY);
// 		while (1)
// 		{
// 			line = get_next_line(fd);
// 			if (line == NULL)
// 				break ;
// 			printf("line: %s", line);
// 		}
// 		test[10] = test[10] + 1;
// 		close(fd);
// 		i++;

// 	}

// 	return (0);
// }