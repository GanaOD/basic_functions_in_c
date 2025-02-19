#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	// error-handling
	if (n == 0)
		return (0);

	// base case: success: hit 1
	if (n == 1)
		return (1);

	// other base case: hit an odd number 
	if (n % 2 != 0)
		return (0);

	// decrease and conquer!
	// into recursion until a base case is hit
	return (is_power_of_2(n / 2));
	
}

int	main()
{
	unsigned int	n; 

	n = 25;
	printf("Int: %d\n, Return result: (1 == multiple of 2, else 0) %d\n", n, is_power_of_2(n));

	n = 32;
	printf("Int: %d\n, Return result: (1 == multiple of 2, else 0) %d\n", n, is_power_of_2(n));
}