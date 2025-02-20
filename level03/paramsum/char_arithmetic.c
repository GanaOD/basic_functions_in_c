int	main(int ac, char **av)
{
	// number of args passed == ac - 1
	// to write, must be char type

	int	nr_args = ac - 1;

	char	nr_args_as_char = nr_args + '0';
	write (1, &nr_args_as_char, 1);
	write (1, "\n", 1);

	return (0);
}

/*
NB.
exploits ASCII encoding where digits are sequential
- adding '0' to an integer n gives the ASCII char for that digit

*/