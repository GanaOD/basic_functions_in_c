#include <unistd.h>

void	alpha_mirror(char *str)
{
	char	mirror;

	while (*str)
	{
		// lowercase
		if (*str >= 'a' && *str <= 'z')
			mirror = ('z' - (c - 'a'));
		// uppercase
		else if (*str >= 'A' && *str <= 'Z')
			mirror = ('Z' - (c - 'A'));
		// other char
		else
			mirror = (*str);

		write (1, &mirror, 1);
		str++;
	}
}