#include <unistd.h>

void	put_nr(int n)
{
	if (n >= 10)
		put_nr(n / 10);
	char	c = n % 10 + '0';
	write (1, &c, 1);
}

int	ft_atoi(char *str)
{
	int num = 0;

	while (*str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}

	return (num);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	number = ft_atoi(argv[1]);

	int	multiplicator = 1;
	while (multiplicator <= 9)
	{
		put_nr (multiplicator);
		write (1, " x ", 3);
		put_nr (number);
		write (1, " = ", 3);
		put_nr (multiplicator * number);
		write (1, "\n", 1);

		multiplicator++;
	}

	return (0);
}
