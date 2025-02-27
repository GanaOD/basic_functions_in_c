#include <unistd.h>

long int	my_atoi(char *str)
{
	long int	result = 0;

	while (*str)
	{
		if (*str >= '0' && *str <= '9') // str content validation before conversion
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (result);
}

void	print_hex_recursive(long int int_base10)
{
	char hex_digits[] = "0123456789abcdef"; // lookup table

	if (int_base10 >= 16)
		print_hex_recursive(int_base10 / 16);

	write (1, &hex_digits[int_base10 % 16], 1);
}

void	print_hex(char *str)
{
	if (!str) // param validation before passing to atoi
		return ;

	// CONVERT STR > INT BASE 10 (default)
	long int	int_base10 = my_atoi(str);

	// CONVERT INT BASE 10 > INT BASE 16 > CONVERT TO CHAR REPRESENTATIONS OF DIGITS & DISPLAY
	print_hex_recursive(int_base10);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	write (1, "\n", 1);
	return (0);
}