// +ve if space
// -ve if not space, i.e. char in word
int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

/*
during iteration from end of str back to beginning:

Sliding pointer window:
ptr_lead: scouts ahead to beginning of word (where peeking ahead reveals space/beginning of word) - so store this too: ptr_begin
ptr_trail: stays at end of word

pass ptr_lead to write & length calculated through difference in ptrs
	letting write handle the iteration internally rather than doing it manually (char by char, iterating ptr_lead back to _trail)
*/

void	rev_wstr(char *str)
{
	char	*ptr_begin = str;

	// iterate through str to end
	while (*str)
		str++;

	// for pointer window:
	char	*ptr_lead = str;
	char	*ptr_trail = str;

	// delimiters / boundary conditions for ptr_lead:
	//		space (start of current word): indicated by +ve return value of is_space
	//		string_begin (special case for 1st word)
	while (!is_space(*ptr_lead) && (ptr_lead != ptr_begin))
		ptr_lead--; // as long as these are not met, continue traversal

	// peek-ahead:
	
	{
		CONVOLUTED ATTEMPT: see docs/category-error
	}

}

int	main(int ac, char **av)
{
	if (ac == 1)
		rev_wstr(av[1]);
	write (1, "\n", 1);
	return (0);
}