// convert each digit from char representation, base 16
// to actual integer / numeric value, base 10 (0-15)
// needed for arithmetic operations
int	get_digit(char c)
{
	if (c)
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result = 0;
	int	sign = 0;
	int	digit;

	// minus signs can only occur at beginning of str
	// 1 suffices to store sign as negative
	// applied to result at end
	if (*str == '-')
		sign = -1, str++;

	while (*str)
	{
		digit = get_digit(*str);

		// validate digit against requested base
		if (digit == -1 || digit >= str_base)
			return (0);

		// build up final number with positional weights
		result = (result * str_base) + digit;
		str++;
	}
	return (result * sign);
}




