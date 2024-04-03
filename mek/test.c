#include "../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	char	*test;

	// test = "tests/test0";
	// fd = open(test, O_RDONLY);
	// printf(" ------ test empty: -----\n");
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	printf("line: %s \n", line);
	// }
	// close(fd);
	// printf(" ---------------------------\n");
	// test = "tests/test1";
	// fd = open(test, O_RDONLY);
	// printf(" ------ test only_nl: -----\n");
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	printf("line: %s \n", line);
	// }
	// close(fd);
	printf(" ---------------------------\n");
	test = "tests/test2";
	fd = open(test, O_RDONLY);
	printf(" ------ test 1char: -----\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line: %s \n", line);
	}
	close(fd);
	printf(" ---------------------------\n");
	test = "tests/test3";
	fd = open(test, O_RDONLY);
	printf(" ------ test 10chr: -----\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line: %s \n", line);
	}
	close(fd);
	printf(" ---------------------------\n");
	test = "tests/test4";
	fd = open(test, O_RDONLY);
	printf(" ------ test 10chr_nl: -----\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line: %s \n", line);
	}
	close(fd);
	printf(" ---------------------------\n");
	test = "tests/test5";
	fd = open(test, O_RDONLY);
	printf(" ------ test crazy: -----\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line: %s \n", line);
	}
	close(fd);
	printf(" ---------------------------\n");
	return (0);
}
// int	main(void)
// {`
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