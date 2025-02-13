#include <unistd.h>

void	jumpseek(char *s1, char *s2)
{
	if (!*s1)
	{
		write (1, "1", 1);
		return ;
	}

	while (*s1 && *s2 && *(s2 + 1))
	{
		while (*s2)
		{
			if (*s2 == *s1)
				s2 += 2, s1++;
			else 
				s2++;
		}
	}
	if (*s1)         // If we still have characters left in s1
    write(1, "0", 1);  // We failed - couldn't find all matches
	else             // If we've consumed all of s1
    write(1, "1", 1);  // Success - found all matches with correct stride
}

int	main(int ac, char **av)
{
	if (ac == 3)
		jumpseek(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}