#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

// is_prime

int	is_prime(int test_number)
{
	if (test_number < 2)
		return (0);
	if (test_number == 2)
		return (1);
	// even number check
	if (!(test_number & 1))
		return (0);
	for (int i = 3; (i * i <= test_number); i += 2)
		if (test_number % i == 0)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	target_nr;
	int	prime_sum;
	int	current_nr;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	target_nr = ft_atoi(argv[1]);
	if (target_nr <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	prime_sum = 0;
	current_nr = 2;
	while (current_nr <= target_nr)
	{
		if (is_prime(current_nr))
			prime_sum += current_nr;
		current_nr++;
	}
	ft_putnbr(prime_sum);
	write(1, "\n", 1);
	return (0);
}
