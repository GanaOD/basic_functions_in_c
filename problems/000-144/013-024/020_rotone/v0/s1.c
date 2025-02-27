#include <unistd.h>

char	new_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (((c - 'a' + 1) % 26) + 'a');
	else if (c >= 'A' && c <= 'Z')
		return (((c - 'A' + 1) % 26) + 'A');
	else
		return (c);
}

void	rotone(char *str)
{
	if (!str)
		return ;

	while (*str)
	{
		char	rotated = new_char(*str);
		write (1, &rotated, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}