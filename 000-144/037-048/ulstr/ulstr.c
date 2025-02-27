#include <unistd.h>

char	swap_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = av[1];
		while (*str)
		{
			char c = swap_char(*str);
			write (1, &c, 1);
			str++; 
		}
	}
	write (1, "\n", 1);
	return (0);
}