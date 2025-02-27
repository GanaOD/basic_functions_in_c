/*

Beginning: start iterating
Set flag: in word / not? Inword = 1 when normal chars. = 0 when we meet a space / tab
When flag goes from 0 > 1 (i.e. we enter a new word in str), write a space, then continue with normal write
This continues until end of str (meet \0)

first condition: if argc == 2 && argv[1]
	logic
followed by (so this also covers when first condition not met) \n

*/

#include <unistd.h>

// Flag
int	is_space(char c)
{
	int	result = 0;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		result = 1;
	return (result);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		space;

	if (argc != 2 || !argv[1])
	{
		write (1, "\n", 1);
		return (0);
	}

	str = argv[1];
	space = 0;

	// Skip leading spaces
	while (*str && is_space(*str))
		str++;

	while (*str)
	{
		if (is_space(*str))
			space = 1;
		else
		{
			if (space)
				write (1, " ", 1);
			write (1, str, 1);
			space = 0;
		}
		str++;
	}
	write (1, "\n", 1);

	return (0);
}
