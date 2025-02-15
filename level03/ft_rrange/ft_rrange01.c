
int	*ft_rrange(int start, int end)
{
	// in order to allocate & store array of ints, need length of array
	// careful: len != diff
	int	len = 0;
	if (end > start)
		len = end - start + 1;
	else if (end < start)
		len = start - end + 1;
	else if (start == end)
		len = 1;

	int *int_array = malloc(sizeof(int) * len);

	int	i = 0;
	if (end > start)
	{
		while (i < len)
		{
			int_array[i] = end;
			i++, end--;
		}
	}
	else if (end < start)
	{
		while (i < len)
		{
			int_array[i] = end;
			i++, end++;
		}
	}
	else if (end == start)
		*int_array = end;

	return (int_array);
}