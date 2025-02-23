#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len = 0;
	
	if (end > start)
		len = end - start + 1;
	else if (end < start)
		len = start - end + 1;
	else (end == start)
		len = 1;

	int	*result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);

	int	i = 0;
	if (end > start)
	{
		while (start <= end)
			result[i++] = start++;
	}
	else if (end < start)
	{
		while (start >= end)
			result[i++] = start--;
	}
	else (start == end)
		result[i] = start;
	return (result);
}
