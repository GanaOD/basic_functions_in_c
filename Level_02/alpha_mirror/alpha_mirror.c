/*
Mathematical reflection, symmetry:

Linear Functions and Reflection:
	The alphabet can be mapped to numbers (a=0, b=1, ..., z=25)
	When we mirror around the middle point (between m and n), we're performing a reflection
	In mathematics, reflection around a point is achieved through the formula: f(x) = 2p - x, where p is the point of reflection
	In our case, with z=25 being our reference point, this simplifies to f(x) = 25 - x


Modular Arithmetic:
	Our alphabet forms a cyclic group of 26 elements
	Each letter maps to exactly one other letter
	The transformation preserves the structure (uppercase stays uppercase, lowercase stays lowercase)

*/


/*
1: Implementation
*/

#include <unistd.h>

char	mirror_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a'));
	if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A'));
	return (c);
}

int	main(int argc, char **argv)
{
	char *str = argv[1];
	if (argc == 2)
	{
		while (*str)
		{
			char c = mirror_char(*str);
			write (1, &c, 1);
			str++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
