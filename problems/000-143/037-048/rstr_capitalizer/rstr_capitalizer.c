#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	
	else // all other chars remain (lowercase alphabetical & other)
		return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	
	else
		return (c);
}

// direct write syscall during traversal
// incrementation of str pointer outside of individual conditions
void	rstr_capitalizer(char *str)
{
	while (*str)
	{
		char	processed_char;

		// 3 possible logic flows:
		
		// pointing to space
		if (is_space(*str))
			write (1, " ", 1);
		
		// pointing to char AND next char is also a char
		// this char is within a word, so lowercase
		else if ((!is_space(*str)) && !is_space(*(str + 1)))
		{
			processed_char = to_lower(*str);
			write (1, &processed_char, 1);
		}

		// pointing to char AND next char is EITHER space OR end of string 
		// this char is last in word / string, so uppercase
		else if ((!is_space(*str)) && (is_space(*(str + 1)) || !(*(str + 1))))
		{
			processed_char = to_upper(*str);
			write (1, &processed_char, 1);
		}

		str++;
	}
}

int	main(int ac, char **av)
{
	if (!av)
		return (0);

	else
	{
		if (ac > 1)
		{
			int	i = 1;
			while (i < ac) // iterates through command-line args
			{
				rstr_capitalizer(av[i]);
				write (1, "\n", 1);
				i++;
			}
		}
		else
			write (1, "\n", 1);
	}
	return (0);
}
