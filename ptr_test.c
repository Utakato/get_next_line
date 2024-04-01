int	main(void)
{
	int i = 0;
	// loop for 12 times calling the test_ptr
	while (i < 12)
	{
		test_ptr();
		i++;
	}
	return (0);
}

void	test_ptr(void)
{
	static char buffer[12] = "Hello World";

	printf("%c\n", *buffer);
	buffer = buffer + 1;
}