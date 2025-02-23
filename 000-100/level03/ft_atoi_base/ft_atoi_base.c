// #include <stdio.h>

// convert digits: 
// 		from char type, base 16
// 		to int type, base 10
int	get_digit(char c)
{
	// digit between 0 and 9
	if (c >= '0' && c <= '9')
		return (c - '0');

	// digit between a and f
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);

	// digit between A and F
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);

	else // with all other input values - invalid
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (!str || str_base <= 1 || str_base > 16)
		return (0);

	// minus signs can only occur at beginning of str
	// 1 occurrence suffices to store sign as negative
	// applied to result at end
	int	sign = 1;
	if (*str == '-')
		sign = -1, str++; // MORE ABSTRACT / OTHER WAY OF 'STORING' SIGN?

	// get_digit provides digits in format needed
	// to iteratively build up with arithmetic the new int in new base
	int	digit;
	int	result = 0;
	while (*str)
	{
		digit = get_digit(*str);

		// validate digit against requested base
		if (digit == -1 || digit >= str_base)
			return (0);
		
		// incrementally build up final nr. with positional weights
		result = result * str_base + digit;

		str++;
	}
	return (result * sign);
}

// int	main()
// {
// 	char	input[] = "face01baba";
// 	int		str_base = 11;

// 	printf("\nInput string, base 16: %s\nNew base: %d\n", input, str_base);
// 	printf("Integer result: %d\n", ft_atoi_base(input, str_base));

// 	printf("\nInteger result: %d\n", ft_atoi_base("face", 16));      // Valid hex

// 	printf("\nInteger result: %d\n", ft_atoi_base("1234", 5));       // Base-5 number

// 	printf("\nInteger result: %d\n", ft_atoi_base("-789", 10));      // Negative decimal

// 	printf("\nInteger result: %d\n", ft_atoi_base("----789", 10));			// >1 minus sign

// 	printf("\nInteger result: %d\n", ft_atoi_base("xyz", 16));       // Invalid digits

// 	printf("\nInteger result: %d\n", ft_atoi_base("1234", 1));       // Invalid base

// 	return (0);
// }