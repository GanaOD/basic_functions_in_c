#include <stdlib.h>

char	*itoa(int nr)
{
	// keep nr as-is as reference pt instead of flag to mark neg. sign

	long int	to_process = nr; 
	// this is what gets processed when converting +ve int > chars

	// -ve int handling 
	// overall idea: convert -ve ints to their +ve values to work with these
	// must be available in len calculation & storage at end
	if (nr < 0)
		to_process = -to_process;

	
	/* str len calculation for malloc (not incl. \0, just chars)*/
	int	str_len = 0;

	/* special case: 0 */
	if (nr == 0)
		str_len = 1;
	else
	{
		/* 
		+ve int handling 
		calculate str len with temp value as consumed in process
		*/
		long int	digit_count = to_process; // which is the +ve value of +ve & -ve ints, which is to be worked with from now on 

		while (digit_count > 0)
		{
			str_len++; // as initialised to 0, to count 1st value before division
			digit_count /= 10;
		}

		if (nr < 0)
			str_len++; // for '-' sign
	}


	/*	malloc str	*/
	char	*final_array = malloc(str_len + 1);
	if (!final_array)
		return NULL;


	/* process int, store chars in array */
	// convert int > chars
	// use modulo operator to extract each char from r > l
	// store directly in char array
	// this movement: r > l means final_array will point to 1st char at end
	// so no need to introduce new ptr for traversal & storage so that beginning is stored
	// don't need str_len variable later, can use up here

	final_array[str_len] = '\0';

	if (nr == 0)
		final_array[0] = '0';
	// keeps digit-processing logic below simpler: it's designed for non-zero numbers

	else
	{
		int	i = str_len - 1;

		while (to_process > 0)
		{
				final_array[i] = (to_process % 10) + '0';
				to_process /= 10;
				i--;
		}

		if (nr < 0)
			final_array[0] = '-';
		// due to decrementation-after-assignment in above logic, could stay with final_array[i] here
		// but this direct approach would avoid potential off-by-1 error & explicitly states intent
	}

	return (final_array);
}

#include <limits.h>
#include <stdio.h>

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
	print_test(test_name, 777, itoa(777));

	test_name = "zero";
	print_test(test_name, 0, itoa(0));

	test_name = "negative int";
	print_test(test_name, -977, itoa(-977));

	test_name = "minimum integer";
	print_test(test_name, INT_MIN, itoa(INT_MIN));

	return (0);
}