#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	pgcd(char *s1, char *s2)
{
	// convert str ints > int ints
	int	i1 = atoi(s1);
	int	i2 = atoi(s2);

	// error check: if non-positive nr / invalid str / atoi conversion fail
	if (!(i1 && i2))
		return ;


	// bounded linear search
	int		divisor;

	if (i1 <= i2)
		divisor = i1;
	else
		divisor = i2;
	// lower int == starting pt

	while (divisor > 0) 
	{
		if ((i1 % divisor == 0) && (i2 % divisor == 0))
			break ;
		divisor--;
	}

	printf("%d\n", divisor);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		write (1, "\n", 1);
	else
		pgcd(av[1], av[2]);
	return (0);
}