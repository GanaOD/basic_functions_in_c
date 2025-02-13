#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	if (end > start)
		len = end - start + 1;
	else if (end < start)
		len = start - end + 1;
	else if (end == start)
		len = 1;
	
	int	*result = malloc(sizeof(int) * len);
	if (!result)
		return NULL;

	int	i = 0;
	if (end > start)
	{	
		while (end >= start)
		{
			result[i] = end;
			i++, end--;
		}
	}
	else if (end < start)
	{
		while (end <= start)
		{
			result[i] = end;
			i++, end++;
		}
	}
	else if (end == start)
		*result = end;
	return (result);
}