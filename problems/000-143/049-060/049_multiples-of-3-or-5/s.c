#include <stdio.h>

int	main()
{
	int	count = 3;
	int	sum = 0;
	while (count < 1000)
	{
		if ((count % 3 == 0) || (count % 5 == 0))
			sum += count;
		count++;
	}
	printf("sum: %d\n", sum);
	return (0);
}