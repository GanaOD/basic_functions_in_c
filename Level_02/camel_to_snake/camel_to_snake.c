#include <unistd.h>
#include <stdlib.h>

/*
Iteration 1
Count nr. of uppercase chars
Count full length of str

malloc enough space for length str + nr. of uppercase chars + 1

Iteration 2
copy each char from str > new malloced str
while iterating through str
	if *str uppercase, write _ and then the char in lower case , then continue iterating

Take 1 cmd line arg
*/

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write (1, "\n", 1);
		return (0);
	}

	// Counting
	char	*str = argv[1];
	char	*ptr = str;
	int		count_upper = 0;
	int		len = 0;

	while (*ptr)
	{
		if (is_upper(*ptr))
			count_upper++;
		len++;
		ptr++;
	}

	// Malloc for new_str:
	char	*new_str = malloc(len + count_upper + 1);
	if (!new_str)
		return (1);

	char	*dst = new_str; // store for freeing later

	while (*str)
	{
		// Assign each char in str to new_str, iterate through str
		// Include camel > snake logic at beginning
		if (is_upper(*str))
		{
			*dst++ = '_';
			*dst++ = (*str + 32);
			str++;
		}
		*dst = *str;
		dst++;
		str++;
	}
	write (1, new_str, (dst - new_str));
	write (1, "\n", 1);
	free (new_str);

	return (0);
}
