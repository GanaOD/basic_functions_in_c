#include <unistd.h>

void	hiddenp(char *s1, char *s2)
{
	while (*s1 && *s2) // iterate through both strings
	{
		if (*s1 == *s2) // when chars match, advance in both
				s1++;
		s2++; // if chars don't match, only advance in s2
	}
    
	if (*s1 == '\0') // if we get to end of s1: success!
			write(1, "1", 1);
	else
			write(1, "0", 1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hiddenp(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}
