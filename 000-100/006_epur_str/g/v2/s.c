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

	// state: in space
	// 	leading / in between words / trailing
	// action: skip
	while (is_space(*str))
		str++;

	// transition: space > word
	if (!is_space(*str) && *str)
	{
		// state: in word
		while (*str && !is_space(*str))
		{
			write (1, str, 1);
			str++;
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