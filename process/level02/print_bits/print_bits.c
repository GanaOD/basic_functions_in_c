#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	nr = octet;
	int	position = 7;
	char	bits[8];

	while (position >= 0)
	{
		bits[position] = (n % 2) + '0'; // storing a single char ('0' or '1') at position i in the bits array
		n = n / 2;
		position--;
	}
	write (1, bits, 8);
}