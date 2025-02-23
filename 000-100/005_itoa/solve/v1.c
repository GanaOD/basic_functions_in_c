#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
	int	len = 1;

	int	n_len = nbr; 				// to calculate nbr length
	int	n_work = nbr; 			// working copy of nbr for malloc'd str
	// separation important: each operation (len counting & digit extraction) consumes the number it works with
	
	int	negative_flag = 0; // set to 1 to track negative nbr
	
	char	*result;

	if (nbr == 0)
	{
		result = malloc(2); 
		if (!result)	return NULL;
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	// index notation to keep result pointing to 1st char

	else
	{
		
		if (nbr < 0)
		{
			// special case: INT_MIN * -1 doesn't fit in int
			if (nbr == INT_MIN)
			{
				result = malloc(10 + 1 + 1); // 10 digits, 1 minus sign, 1 null determiner
				if (!result)	return NULL;
				result[0] = '-', result[1] = '2', result[2] = '1', result[3] = '4',
				result[4] = '7', result[5] = '4', result[6] = '8', result[7] = '3',
				result[8] = '6', result[9] = '4', result [10] = '8', result[11] = '\0';
				return (result);
			}
			else
			{
				// make both working copies of nbr +ve for upcoming logic
				n_len = n_len * -1;
				n_work = n_work * -1;
				negative_flag = 1; 
			}
		}


		// for positive nbrs:
		// calculate nr. of digits == nr. of chars in str
		while (n_len >= 10)
		{
			len++;
			n_len = n_len / 10;
		}
		// special case: original nbr negative: 1 more space needed for minus sign
		if (negative_flag == 1)
			len++;


		// malloc str
		result = malloc(sizeof(char) * (len + 1));
		if (!result)
			return (NULL);


		// fill str: store each digit as char from r > l
		result[len] = '\0';
		len--; // move to last digit position
		while (n_work > 0) // also handle single digits
		{
			result[len] = (n_work % 10) + '0'; // convert digit to char, assign to position in str
			n_work = n_work / 10; // "remove" this digit for next iteration
			len--;
		}
		if (negative_flag == 1)
			result[len] = '-';

	}

	return (result);
}

void	print_test(char *test_name, int nbr, char *result)
{
	printf("test name: %s\n", test_name);
	printf("original int: %d\n", nbr);
	printf("resulting string: %s\n\n", result);
}

int	main()
{
	char	*test_name;
	printf("\n");

	test_name = "positive int";
	print_test(test_name, 777, ft_itoa(777));

	test_name = "zero";
	print_test(test_name, 0, ft_itoa(0));

	test_name = "negative int";
	print_test(test_name, -977, ft_itoa(-977));

	test_name = "minimum integer";
	print_test(test_name, INT_MIN, ft_itoa(INT_MIN));

	return (0);
}