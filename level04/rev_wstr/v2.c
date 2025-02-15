#include <unistd.h>
#include <stdio.h>

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


Boundary conditions / delimiters for ptr_lead:
	1.	space (start of current word): indicated by +ve return value of is_space
	2.	string_begin (special case for 1st word)
*/

void	rev_wstr(char *str)
{
	// store beginning of string for boundary condition 2
	char	*ptr_begin = str;

	// iterate through str to end
	while (*str)
		str++;

	// for pointer window:
	char	*ptr_lead = str - 1;
	char	*ptr_trail = str - 1;
	
	while (ptr_lead >= ptr_begin) // string domain
	{    
		// Find start of current word, move through spaces at end of str
		while (ptr_lead >= ptr_begin && !is_space(*ptr_lead))
			ptr_lead--;

    // If not last word to write (which is first in original string)
    if (ptr_trail != str - 1)  
        write(1, " ", 1);
        
    // Write word
    write(1, (ptr_lead + 1), (ptr_trail - ptr_lead));

		// traverse space between words
		while (ptr_lead >= ptr_begin && !is_space(*ptr_lead))
			ptr_lead--;
		
		// set up window for next word
		ptr_trail = ptr_lead;

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