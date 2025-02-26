#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ');
}
// returns 1 if char is a space

void	rev_wstr(char *str)
{
	char	*ptr_lead = str;
	// to store str as termination pt in upcoming logic

	while (*ptr_lead)
		ptr_lead++; // iterates through to \0
	ptr_lead--; // point to last char in str

	char	*ptr_trail = ptr_lead; // for ptr window. will be re-set to last char of each word

	while (ptr_lead >= str) // global termination pt: beginning of str
	{
		ptr_trail = ptr_lead;
		
		// find start of current word
		while (ptr_lead >= str && !is_space(*ptr_lead))
			ptr_lead--; // iterates into space before word

		// display word
		write (1, ptr_lead + 1, ptr_trail - ptr_lead);

		// add space if not last word to display (if not 1st word of str)
		if (ptr_lead >= str)
			write (1, " ", 1);

		// skip spaces before next word
		while (ptr_lead >= str && is_space(*ptr_lead))
			ptr_lead--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	else
		write (1, "\n", 1);
	return (0);
}