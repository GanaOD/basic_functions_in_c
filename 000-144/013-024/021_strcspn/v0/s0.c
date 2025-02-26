/*
iterate through s1 & reject str, comparing chars with each increment
continue as long as *s1 != *reject

stop iterating when:
- the value at s1 == char at reject, find this array index
if this condition isn't met, then stop at first null, also return its index


"RETURN VALUES
     The strspn() and strcspn() functions return the number of characters spanned."
but isn't the index value 1 less than the nr. of chars spanned?

I originally tried a back-to-front logic: I was checking each char in s against 1st char in reject, then incrementing reject
More efficient: for each char in s, first iterate through all chars in r
*/


#include "stddef.h"
#include "stdio.h"
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char *s_start = s;
	const char *r;

	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (s - s_start);
			r++;
		}
		s++;
	}
	return (s - s_start);
}

int	main()
{
	char	*s, *reject;

	printf("\n%s\n", "Test 1: Basic Case");
	s = "Hello", reject = "l";
	printf("%s %zu\n", "My result:", (ft_strcspn(s, reject)));
	printf("%s %zu\n", "Real strcspn result:", strcspn(s, reject));

	printf("\n%s\n", "Test 2: Long String S");
	s = "ReallyReallyReallyLongLongLongString", reject = "S";
	printf("%s %zu\n", "My result:", (ft_strcspn(s, reject)));
	printf("%s %zu\n", "Real strcspn result:", strcspn(s, reject));

	printf("\n%s\n", "Test 3: Long String Reject");
	s = "ReallyReallyReallyLongLongLongString", reject = "NNNNNNNNNNNNNNnnnnnnnnnnnnnnnnnnnnnnnZZZZZZZZZZZZZZZZZZS";
	printf("%s %zu\n", "My result:", (ft_strcspn(s, reject)));
	printf("%s %zu\n", "Real strcspn result:", strcspn(s, reject));

	printf("\n%s\n", "Test 4: Long String Reject");
	s = "ReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongStringReallyReallyReallyLongLongLongString", reject = "0";
	printf("%s %zu\n", "My result:", (ft_strcspn(s, reject)));
	printf("%s %zu\n\n", "Real strcspn result:", strcspn(s, reject));

	return (0);
}
