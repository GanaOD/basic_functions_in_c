unsigned int	lcm(unsigned int a, unsigned int b)
{
	// PARAM VALIDATION
	if (a == 0 || b == 0)
		return (0);

	if (a == b)
		return (a);
	
	// CALCULATE HCF
	unsigned int	count;
	if (a > b)
		count = b;
	else if (a < b)
		count = a;
	
	unsigned int	hcf = 1;
	while (count > 1)
	{
		if ((a % count == 0) && (b % count == 0))
			hcf = count;
		count--;
	}

	// CALCULATE LCM
	unsigned int	result = ((a / hcf) * b);

	return (result);
}

#include <stdio.h>

int	main()
{
	unsigned int	a = 15;
	unsigned int	b = 20;
	unsigned int	result = lcm(a, b);
	printf("%d\n", result);
	
	return (0);
}