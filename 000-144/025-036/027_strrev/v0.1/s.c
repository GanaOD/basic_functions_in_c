char	*strrev(char *str)
{
	char	*str_begin = str;
	char	*end = str;

	while (*end)
		end++;
	end--;

	char	temp;
	while (str_begin < end)
	{
		temp = *str_begin;
		*str_begin = *end;
		*end = temp;

		str_begin++;
		end--;
	}
	return (str);
}

#include <stdio.h>

int	main()
{
	char	str[] = "Hoohaaahooooohalala";
	printf("%s\n", strrev(str));
	return (0);
}