#include <unistd.h>

// input conversion: char array > integer for arithmetic
int	atoi(char *str)
{
	// not checking for -ve values or 0 as subj states
	// param will strictly be +ve nr
	int	result = 0;
	while (*str)
	{
		// no integer overflow check: will fit in an int
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result);
}

// convert int > str & display
void	put_nbr(int nbr)
{
	char	digit;
	if (nbr >= 10)
        put_nbr(nbr / 10);
  digit = (nbr % 10) + '0';
  write(1, &digit, 1);
}

void	tab_mult(char *str)
{
	// ensure I pass a string with valid content (only nrs) to atoi
	char	*temp = str;
	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
			return ;
		temp++;
	}

	int	to_process = atoi(str);

	// display multiplication table
	// includes arithmetic and calling put_nbr helper to write integers
	int	count = 1;
	while (count < 10)
	{
		put_nbr(count);
		write(1, " x ", 3);
		put_nbr(to_process);
		write(1, " = ", 3);
		put_nbr(count * to_process);
		write(1, "\n", 1);
		count++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!av[1]) // ensure I pass valid str ptr to tab_mult...redundant!
			return (1);
		else
			tab_mult(av[1]);
	}
	else
		write (1, "\n", 1);
	return (0);
}