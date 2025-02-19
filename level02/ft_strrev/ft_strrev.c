char	*ft_strrev(char *str)
{
	// 2-ptrs, moving towards middle

	// ptr to iterate & carry out swaps
	// str will store beginning for function return
	char	*str_from_start = str;

	// set up initial end ptr position
	char	*str_from_end = str;
	while (*(str_from_end + 1))
		str_from_end++;
	
	// for swapping
	char	temp;

	// minimal loop condition to meet in the middle
	// 	odd-length str: ptrs meet (start == end)
	//	even-length str: ptrs cross (start > end or end > start)
	while (str_from_start < str_from_end) // 1 condition: captures both termination cases
	{
		temp = *str_from_end;
		*str_from_end = *str_from_start;
		*str_from_start = temp;
		str_from_start++, str_from_end--;
	}

	return (str);
}