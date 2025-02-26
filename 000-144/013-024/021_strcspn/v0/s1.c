#include <stdio.h>

size_t	strcspn(const char *s, const char *reject)
{
	if (!s || !reject)
		return (0);

	size_t	i = 0;
	
	while (s[i] != '\0')
	{
		size_t	j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// int	main()
// {
// 	char	*s = "Welcome Home Buddy";
// 	char	*reject = "c";
// 	size_t	result = strcspn(s, reject);
// 	printf("%zu", result);

// 	return (0);
// }
