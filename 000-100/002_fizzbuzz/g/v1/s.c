#include <unistd.h>

/*
Arithmetic operations carried out out on the numbers
So need them as ints

To display with write, need as chars
*/

void	putnr(int nr)
{
	if (nr >= 10)
		putnr(nr / 10);
	write (1, &(char){(nr % 10) + '0'}, 1);
}

int	main()
{
	int	nr = 1;
	while (nr <= 100)
	{
		if ((nr % 3 == 0) && (nr % 5 == 0))
			write (1, "fizzbuzz", 8);
		else if (nr % 3 == 0)
			write (1, "fizz", 4);
		else if (nr % 5 == 0)
			write (1, "buzz", 4);
		else if (nr >= 10)
			putnr(nr);
		write (1, "\n", 1);
		nr++;
	}
	return (0);
}