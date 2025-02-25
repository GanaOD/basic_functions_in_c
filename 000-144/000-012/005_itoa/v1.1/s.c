#include <stdlib.h>

/* 
No use of limits.h, not yet fluent in man-page use 
so manual calculation of INT_MIN
interested in its value, not sign here
*/

// Calculate 2^31 (2 raised to power 31)
// Using multiplication since C has no exponentiation operator
long int	calculate_int_min()
{
	long int	result = 1; // 2 ^ 0
	int	count = 0;
	while (count < 31)
	{
		result *= 2;
		count++;
	}
	return (result);
}

// display INT_MIN value in stdout
#include <stdio.h>

int main(void)
{
    printf("INT_MIN = %d\n", calculate_int_min());
    return (0);
}

/* 
could then use: 
#define MY_INT_MIN (-2147483648)
*/



char	*itoa(int nr)
{

	/* special case: 0 */
	if (nr == 0)
	{
		int	str_len = 0;
	}
	// see if I can use logic later on from +ve value handling for 0



	/* -ve int handling */

	// flag: if +ve, 0. else if -ve, 1
	int	neg = 0; 
	// will be used in str_len calculation & storage of chars

	else if (nr < 0)
	{
		neg = 1;

		// special case: INT_MIN
		if (nr == MY_INT_MIN)
		{
			(long int)MY_INT_MIN;
		}
		else
			nr = nr * -1;
	}


	/* +ve int handling */

	// temp value to calc. str len
	// consumed in process
	int	digit_count = nr;  

	while (digit_count > 0)
	{
		digit_count /= 10;
		str_len++;
	}
	// keep digit count just for nr. of digits
	// extra char position for -ve sign with -ve ints dealt with in malloc


	// malloc ze string
	char	*final_array;

	final_array = malloc

}