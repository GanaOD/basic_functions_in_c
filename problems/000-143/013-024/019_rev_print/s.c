#include <unistd.h>

void	rev_print(char *str)
{
	if (!str)
		return ;

	char	*str_begin = str;

	while (*str)
		str++;
	str--;

	while (str >= str_begin)
	{
		write (1, str, 1);
		str--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	write (1, "\n", 1);
	return (0);
}