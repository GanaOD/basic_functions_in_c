/*
PLAN
to check for duplicates, need to remember which chars have been seen
Hence a buffer that serves as "memory", into which each unique char encountered gets stored

This allows function to:
	Track what's been seen in a single pass through each string
	Avoid nested loops through previous characters
	Maintain order of appearance from command line

gives O(n) scanning 
instead of O(n²) that would come from checking each char against all previous chars in the strings
*/

// have we seen this char before?
// checks memory buf
int	was_used(char *used_buf, char c, char *used_end)
{
	while (used_buf < used_end)
	{
		if (*used_buf == c)
			return (1);
		used_buf++;
	}
	return (0); // only if every char has been checked without finding match
}

void	union(char *s1, char *s2)
{
	char	used_buf[256]; // fixed-sized array: covers full ascii range
	char	*used_end = used_buf;

	while (*s1)
	{
		if (!was_used(used_buf, *s1, used_end)) // this char has not been encountered & stored in buf
		{
			*used_end = *s1;	// store this new char in used_buf
			used_end++, s1++; // when new char stored, also increment used_end forwards
			// used_end marks insertion pt for new unique chars
			// & acts as boundary for how far was_used should search through buffer
		}
		else // we have seen this char before: no need to store
			s1++;
	}

	while (*s2)
	{
		if (!was_used(used_buf, *s2, used_end))
		{
			*used_end = *s2;
			used_end++, s2++;
		}
		else
			s2++;
	}

	// both strings checked
	// used_buf contains all unique chars in order of appearance
	// can write in 1 write syscall pass as state has been maintained in used_buf
	// & used_end has tracked end
	write (1, used_buf, (used_end - used_buf)); 
	// len calculation doesn't need a +1 as used_end points 1 past last stored char
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union(av[1], av[2]);
	write (1, "\n", 1);

	return (0);
}