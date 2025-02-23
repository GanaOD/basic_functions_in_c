/*
char *
     strcpy(char * dst, const char * src);

copy the string src to dst (including
     the terminating `\0' character.)

... return dst
*/

char    *ft_strcpy(char *s1, char *s2)
{
	char	*s1_cpy = s1;
	// new ptr for copy operations
	// store s1 at beginning to return later
	while (*s2)
	{
		*s1_cpy = *s2;
		s2++, s1_cpy++;
	}
	*s1_cpy = '\0';
	return (s1)
}