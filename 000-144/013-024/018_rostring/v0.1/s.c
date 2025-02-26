#include <unistd.h>
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	rostring(char *str)
{
	if (!str)
		return ;

	while (*str) // global boundary: until end of str
	{
		// STATE: IN LEADING SPACE
		while (is_space(*str))
			str++; // iterates into first char of first word
		

		// pointer window
		// will use str as ptr_lead: doesn't need storage
		char	*ptr_trail = str; 


		// SPECIAL CASE: FIRST WORD
		int		len = 0;
		while ((!is_space(*str)) && *str)
		{
			len++; // begin by counting 1st char of 1st word
			str++; // iterate until space after word
		}

		char	*first_word = malloc(sizeof(char) * (str - ptr_trail + 1));
		if (!first_word)
			return ;
		
		// assignment, storage in malloc'd str:
		int	count = 0;

		while (count < len)
		{
			first_word[count] = ptr_trail[count];
			count++;
		}
		first_word[count] = '\0';


		// GENERAL LOGIC: REST OF STR
		while (*str)
		{
			// state: in space between words
			while (is_space(*str))
				str++;
			
			// state: in word and not end of str
			if (*str) // implicitly no longer in space, so only check for end of str
			{
				// process & write word
				while (!is_space(*str) && *str)
				{
					write (1, str, 1);
					str++;
				}
				// str now points to a space / end of str

				// to decide whether to write space, need to check if there's an upcoming word
				// need to peek ahead to see if there are any non-space characters 
				// after current spaces. But we can't permanently advance str yet 
				// because we're still in the middle of our loop
				// therefore temp pointer
				char	*temp = str; 
				while (is_space(*temp))
					temp++; // skip through upcoming spaces

				if (*temp) // if not null after skipping spaces, means there's another word, so write 1 space
					write(1, " ", 1);
			}
		}
		// have now reached end of str that was passed

		// DISPLAY STORED WORD
		write (1, " ", 1);
		count = 0; // reinitialise
		while (count < len)
		{
			write (1, &first_word[count], 1);
			count++;
		}

		free (first_word);
	}

		
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write (1, "\n", 1);
	return (0);
}