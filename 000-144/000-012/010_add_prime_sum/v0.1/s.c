# include <unistd.h>

/*	INPUT TRANSFORMATION	*/
// Input validation and conversion (raw character data → numeric value)
int	ahoi_atoi(char *str)
{
	int	result = 0;

	if (!*str)
		return (0);
	
	while (*str) 
	{
		if (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
		else
			return (0);
	}
	return (result);
}


/*	COMPUTATION HELPER 	*/
int is_prime(int n)
{
	int i;
	
	if (n <= 1)
			return (0);  // 0 and 1 are not prime
	
	if (n == 2)
			return (1);  // 2 is prime
	
	if (n % 2 == 0)
			return (0);  // Even numbers other than 2 are not prime
	
	// Check odd divisors up to the square root of n
	i = 3;
	while (i * i <= n)
	{
			if (n % i == 0)
					return (0);
			i += 2;  // Skip even numbers
	}
	return (1);
}


/*	OUTPUT TRANSFORMATION		*/
// convert prime_sum from int > char, display
void	display_prime_sum(int prime_sum)
{
	if (prime_sum >= 10)
		display_prime_sum(prime_sum / 10);

	char	digit = (prime_sum % 10) + '0';
	write (1, &digit, 1);
}


/*	ORCHESTRATION	+ MAIN COMPUTATION	*/

// calculate prime_sum
void	add_prime_sum(char *str)
{
	int	input = ahoi_atoi(str);

	int	count = 0; // begin at 0th index
	int	prime_sum = 0;

	if (input <= 0)
	{
		write (1, "0", 1);
		return ;
	}

	while (count < input)
	{
		if (is_prime(count))
			prime_sum += count;
		count++;
	}

	display_prime_sum(prime_sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		add_prime_sum(av[1]);
	else
		write (1, "0", 1);
	write (1, "\n", 1);
	return (0);
}