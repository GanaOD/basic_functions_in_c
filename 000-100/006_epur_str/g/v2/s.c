#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else 
		return (0);
}

void	epur(char *str)
{
	if (!str)
		return ;
	
	// SPECIAL CASE

	// state: in leading space
	while (is_space(*str))
		str++;

	// state: first word (if exists)
	while (*str && !is_space(*str))
	{
		write(1, str, 1);
		str++;
	}

	// > GENERAL PATTERN: subsequent words
	while (*str)
	{
		// Skip spaces
		while (is_space(*str))
				str++;
		
		// If another word found
		if (*str)
		{
				write(1, " ", 1);  // Space between words
				while (*str && !is_space(*str))
				{
						write(1, str, 1);
						str++;
				}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur(av[1]);
	write (1, "\n", 1);
	return (0);
}