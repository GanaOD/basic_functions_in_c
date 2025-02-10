/*
Iterate through both strings
Compare value of each char
If not equal, subtract: s1 - s2, returns int
*/

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
		s1++, s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main()
// {
// 	char s1[] = "Hello, world";
// 	char s2[] = "Hello, World";
// 	int result = ft_strcmp(s1, s2);
// 	printf("%d\n", result);
// }
