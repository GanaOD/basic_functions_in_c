#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	// don't need str param error check !str 
	// or check whether str contents (chars) are valid
	// these both guaranteed by subj

	int	nbr = atoi(str);

	if (nbr == 1)
	{
		printf("1");
		return ;
	}
	
	int	factor = 2;
	int	first_factor = 1; // flag for output formatting

	while (nbr > 1)
	{
		if (nbr % factor == 0)
		{
			if (first_factor)
				first_factor = 0;
			else
				printf("*");

			printf("%d", factor);
			nbr /= factor;
		}
		else
			factor++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}