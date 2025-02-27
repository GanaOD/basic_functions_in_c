#include <unistd.h>
#include <stdio.h>

// input conversion
int	str_to_int(char *str)
{
	// param check in pgcd

	int	result = 0;
	// moving l > r: process each char (convert to int with asci arithmetic)
	// & build int in process (weighted build up)
	while (*str)
	{
		result = (result * 10) + (*str - '0');
		str++;
	} 
	return (result);
}

// functionality: hcd
int	hcd(int int1, int int2)
{
	// algorithm: decrement from lower of the 2 integers (hcd cannot be > this)
	// check if a nr is a factor with: nr % count_value == 0
	// compare results with both ints
	// 1st one that's equal is highest common factor
	if (int1 == 0) return int2;
  if (int2 == 0) return int1;

	int	count_value;
	
	if (int1 >= int2)
		count_value = int2;
	else
		count_value = int1;

	while (count_value > 1)
	{
		if ((int1 % count_value == 0) && (int2 % count_value == 0))
			return (count_value);
		count_value--;
	}
	return (1);
}

// orchestration: functionality
void	pgcd(char *s1, char *s2)
{
	if (!s1 || !s2)
		return ;

	// validate inputs contain only digits
	char	*temp; 
	
	temp = s1;
	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
			return ; 
		temp++;
	}

	temp = s2;
	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
			return ;
		temp++;
	}

	int	int1 = str_to_int(s1);
	int	int2 = str_to_int(s2);

	if (int1 == 0 || int2 == 0)
		return ;

	int	result = (hcd(int1, int2));

	printf("%d", result);
}

// orchestration: prog
int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(av[1], av[2]);
	printf("\n");
	return (0);
}