// #include <stdio.h>

// incrementally checking multiples

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	multiple;

	if (!a || !b)
		return (0);

	multiple = (a > b) ? a : b;

	while (1)
	{
		if (multiple % a == 0 && multiple % b == 0)
			return (multiple);
		multiple++;
	}
}

// int	main(void)
// {
// 	int	a = 5;
// 	int	b = 6;

// 	printf("2 integers: %d and %d\n", a, b);
// 	printf("LCM: %d\n", lcm(a, b));

// 	return (0);
// }