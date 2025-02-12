// searching within s1 for the 1st occurrence of any char in s2
// return pointer to this char in s1

// nested search pattern

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*s2_scout = s2;

	while (*s1)
	{
		while (*s2_scout)
		{
			if (*s1 == *s2_scout)
				return ((char *)s1);
			s2_scout++;
		}
		s2_scout = s2;
		s1++;
	}
	return (NULL);
}

int	main()
{
	char	s1[] = "Hallihaloo";
	char	s2[] = "jxi";
	char	*result = ft_strpbrk(s1, s2);
	printf("Result: %s\n", result);
	return (0);
}