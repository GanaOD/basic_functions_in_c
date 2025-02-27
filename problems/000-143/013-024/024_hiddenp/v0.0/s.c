#include <unistd.h>

void	hiddenp(char *s1, char *s2)
{
	while (*s1)
	{
		while (*s2 && !(*s2 == *s1))
			s2++;
		if (!*s2)
		{
			write (1, "0", 1);
			return;
		}
		s1++, s2++;
	}
	write (1, "1", 1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hiddenp(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}