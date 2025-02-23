#include <stdio.h>
#include <stdlib.h>

void	pgcd(char *s1, char *s2)
{
	// convert: str > int
	int	int1 = atoi(s1);
	int	int2 = atoi(s2);

	// declaration + initialisation together
	// atoi validity check would need to be separate
	// not necessary with subj conditions


	// arithmetic: bounded-linear search
	// to calculate HCF that matches between both ints
	// 		instead of more complicated decrementing logic
	// 		to implemenent the little reduction in search space (v1.1 notes)
	//		will stay with simple approach

	int		divisor;
	// Starting point (minimum of the two numbers)
	// Counter that gets decremented
	// and eventually holds answer (HCD)

	if (int1 <= int2)
		divisor = int1;
	else
		divisor = int2;
	
	while (divisor > 0)
	{
		if ((int1 % divisor == 0) && (int2 % divisor == 0))
			break ; // exit loop when HCD found
		divisor--;
	}

	// HCD has been found
	// display followed by newline
	printf("%d\n", divisor);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		printf("\n");
	else
		pgcd(av[1], av[2]);
	return (0);
}