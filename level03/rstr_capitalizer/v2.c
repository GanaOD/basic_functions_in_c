// for multiple consecutive spaces. only alphabetical chars need case-modification logic
int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

// CASE-MODIFICATION FUNCTIONS
// map letters → case-modified letters
// everything else → identity function (x → x) (non-letter char handling edge case)

// logic purposely kept explicit: could instead only deal explicitly with chars to convert
// else return as-is

// for all chars in words except last:
//		keeps lowercase chars lowercase
//		converts upper > lowercase
char	to_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	else if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else 
		return (c);
}

// for last char of each word:
//		keeps uppercase chars uppercase
//		converst lower > uppercase
char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else if (c >= 'A' && c <= 'Z')
		return (c);
	else
		return (c);
}


void	rstr_capitaliser(char *str)
{
	while (*str) // global boundary for string processing: until end of str
	{
		// 2 main logic branches:
		// if space: just write
		// if not space: char-conversion logic
		if (is_space(*str))
			write (1, str, 1);
		else
		{
			// peek-ahead to check against boundary conditions
			// this output determines which case-conversion logic to employ
			if (is_space(*(str + 1)) || (!*(str + 1))) // if next char is space OR null determiner
				to_upper(*str);
			else
				to_lower(*str);
			write (1, str, 1);
			str++;
		}
	}
}


int	main(int ac, char **av)
{
	int	array_ptr = 1; // start processing from 2nd command-line arg

	while (array_ptr < ac)
	{
		rstr_capitaliser(av[array_ptr]);
		write (1, "\n", 1); // subject expects newline after writing of each arg
		array_ptr++;
	}

	write (1, "\n", 1);

	return (0);
}