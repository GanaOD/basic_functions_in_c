#include <unistd.h>

// +ve if space
// -ve if not space, i.e. char in word
int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void	rev_wstr(char *str)
{
	// store beginning of string for boundary condition 2
	char	*ptr_begin = str;

	// iterate through str to end: to last char
	while (*(str + 1))
		str++;

	// pointer window:
	char	*ptr_lead = str;
	char	*ptr_trail; // initialise later when last char of 1st word located
	
	while (ptr_lead >= ptr_begin)
	{
		while ((ptr_lead >= ptr_begin) && is_space(*ptr_lead)) // move through spaces
			ptr_lead--;
			// terminates pointing to last char of word
		
		ptr_trail = ptr_lead; // point trail to last char in word

		while ((ptr_lead >= ptr_begin) && !is_space(*ptr_lead)) // iterate through to 1st char of word
			ptr_lead--;
			// terminates at space before 1st char of word (doch keine boundary handling wie geplant: char > char)
			// so that ptr_lead is naturally positioned, ready for next iteration, moving from space

		// window holding word, now write
		write (1, (ptr_lead + 1), (ptr_trail - ptr_lead));

		if (ptr_lead > ptr_begin)
			write (1, " ", 1);

		else
			return ;
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