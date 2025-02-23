#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

void	first_word(char *str)
{
	while (*str && is_space(*str))
		str++;
	while (*str && !(is_space(*str)))
	{
		write (1, str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		first_word(av[1]);
	write (1, "\n", 1);
	return (0);
}