#include <unistd.h>

int	is_word(char c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (0);
	return (1);
}

void	expand_str(char *str)
{
	int	in_word_flag = 0;

	while (*str)
	{
		// space handling
		if (!is_word(*str))
			in_word_flag = 0, str++;

		// write words
		else if (is_word(*str))
		{
			in_word_flag = 1;
			write (1, str, 1);
			str++;
		}			
		
		if (!is_word(*str) && in_word_flag == 1) // transition: word > space: now consider whether more words / end of str
		{
			while (!is_word(*str) && *str) // skip multiple spaces
				str++;
			if (*str) // if now entered a new word, not end of str
				write (1, "   ", 3);
			str--;		// compensate for main loop's increment
		}
	}
	write (1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write (1, "\n", 1);
	return (0);
}