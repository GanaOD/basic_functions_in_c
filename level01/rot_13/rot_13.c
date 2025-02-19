#include <unistd.h>

char	rotate_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (((c - 'a' + 13) % 26) + 'a');
	else if (c >= 'A' && c <= 'Z')
		return (((c - 'A' + 13) % 26) + 'A');
	else
		return (c);
}

void	rot_13(char *str)
{
	while (*str)
	{
		char	result = rotate_char(*str);
		write (1, &result, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write (1, "\n", 1);
	return (0);
}