#include <stdlib.h>

/*
The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.
*/

char	*ft_strdup(char *src)
{
	if (!src)
		return NULL;

	char	*src_ptr = src;
	int		len = 0;
	while (*src_ptr)
	{
		len++;
		src_ptr++;
	}

	char	*result = malloc(len + 1);
	if (!result)
		return NULL;

	char	*result_ptr = result;
	src_ptr = src;
	// reset as generally good practice to preserve input parameters
	// & in case of unexpected behaviour
	while (*src_ptr) 
	{
		*result_ptr = *src_ptr;
		result_ptr++;
		src_ptr++;
	}
	*result_ptr = '\0';
	return (result);
}