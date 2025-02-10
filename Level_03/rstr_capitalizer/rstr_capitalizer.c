#include <unistd.h>

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// For last letter of each word

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	process_string(char *str)
{
	char	*curr = str;
	char	transformed;

	while (*curr)
	{
		transformed = *curr;
		if (!is_space(*curr) && is_letter(*curr))
		{
			if (!*(curr + 1) || is_space(*curr + 1))
				transformed = to_upper(*curr);
			else
				transformed = to_lower(*curr);
		}
		write (1, &transformed, 1);
		curr++;
	}


}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	i = 1;
	while (i < argc) // outermost loop, iterating through command-line args
	{
		process_string(argv[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
