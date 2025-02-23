#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int	len = 1;
	int	temp = nbr; // to preserve original

	// calculate nr. of digits == nr. of chars in str
	while (temp >= 10)
	{
		len++;
		temp = temp / 10;
	}

	// malloc str
	char	*result;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);

	// fill str: store each digit as char from r > l
	result[len] = '\0';
	len--; // move to last digit position
	while (nbr > 0) // also handle single digits
	{
		result[len] = (nbr % 10) + '0'; // convert digit to char, assign to position in str
		nbr = nbr / 10; // "remove" this digit for next iteration
		len--;
	}

	return (result);
}

int	main()
{
	int	nbr;
	char	*result;

	nbr = 777;
	result = ft_itoa(nbr);
	printf("Resulting string: %s\n", result);

	return (0);
}