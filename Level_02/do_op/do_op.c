/*
Arg check: if argc != 4
write newline, exit

else, (implicit) carry out prog logic

convert strings from char* str > signed int
- can call atoi for this ("asci to integer")

ensure "-" char makes signed int a negative number
- this handled by atoi

carry out normal arithmetic
- how? will the 2nd str: the char representing an arithmetic operator get interpreted as correct operator?
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		write (1, "\n", 1);
		return (1);
	}

	int	nr1 = atoi((const char *)argv[1]);
	int	nr2 = atoi((const char *)argv[3]);
	int	result;

	switch (argv[2][0])
	{
		case '+':
			result = nr1 + nr2;
			break;
		case '-':
			result = nr1 - nr2;
			break;
		case '*':
			result = nr1 * nr2;
			break;
		case '/':
			if (nr2 == 0)
				return (write (1, "\n", 1), 1);
			result = nr1 / nr2;
			break;
		case '%':
			if (nr2 == 0)
				return (write(1, "\n", 1), 1);
			result = nr1 % nr2;
			break;
	}

	printf("%d\n", result);

	return (0);
}
