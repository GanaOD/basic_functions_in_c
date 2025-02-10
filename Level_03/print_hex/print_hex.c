#include <unistd.h>

int	ft_atoi(char *str)
{
	int result = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result);
}

void	put_hex(int nr)
{
	// Look up table
	char	*digits = "0123456789abcdef";

	// Recursion
	if (nr >= 16)
		put_hex(nr / 16);

	// Access char from array. Assign value to nr. Implicit conversion > char
	nr = digits[nr % 16];
	write (1, &nr, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		put_hex(ft_atoi(argv[1]));
	write (1, "\n", 1);

	return (0);
}
