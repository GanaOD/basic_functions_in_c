#include <unistd.h>

void	mia_putchara(int i)
{
	if (i >= 10)
		mia_putchara(i / 10);
	
	char	result = (i % 10) + '0';
	write(1, &result, 1);
}

int	main(int ac, char **av)
{
	(void)av;
	
	mia_putchara(ac - 1);
	write (1, "\n", 1);

	return (0);
}