char	*ft_strrev(char *str)
{
	if (!str)
		return NULL;

	char	*end = str;
	while (*end)
		++end;
	--end;

	char	temp;
	char	*start = str;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++, end--;
	}
	return (str);
}

/*
Quick active recall practice (of concepts)

Pre-increment (++end) more idiomatic than post-increment when we don't need the original value
more concise while remaining clear
avoids the potentially confusing pointer arithmetic of *(end + 1)

*/