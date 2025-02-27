#include <stdlib.h>

int	is_delim(char c, char delim)
{
	if (c == delim)
		return (1);
	else
		return (0);
}

char	**ft_split_mod(char *str, char delim)
{
	if (!str)
		return (NULL);
	
	// variables that need whole function scope:
	int	is_delim_flag = 0; // if delim: 1, else 0
	int	seg_count = 0;

	char	*str_begin = str; // store beginning of str, to reset str for 2nd pass

	// 1st pass
	while (*str)
	{
		// leading delims / transition: seg > delim
		if (is_delim(*str, delim) && is_delim_flag == 0)
		{
			is_delim_flag = 1; // state update: in delim(s)
			while (*str && is_delim(*str, delim))
				str++;
			seg_count++;
		}
		// transition: delim > seg
		else if (!is_delim(*str, delim) && is_delim_flag == 1)
		{
			is_delim_flag = 0; // state update: in seg
			while (*str && !is_delim(*str, delim))
				str++;
			seg_count++; // counting after confirmation of valid segment
		}
	}

	// overall_array mallocation
	char	**overall_array = malloc(sizeof(char *) * (seg_count + 1));
	if (!overall_array)
		return (NULL);


	// 2nd pass: pointer window to process each seg:
	// store each seg in overall_array

	// ptr window:
	//		str:	 				leading to end of word
	//		ptr_trail:		storing beginning of word
	//		len between:	needed for malloc

	// reset:
	str = str_begin;
	is_delim_flag = 0;

	int		array_seg_index = 0; // index of array within overall_array

	while (*str)
	{
		char	*ptr_trail = str;

		// leading delim
		// OR transition: seg > delim
		// handling empty segs
		if (is_delim(*str, delim) && !is_delim_flag)
		{
			is_delim_flag = 1; // state reset

			while (*str && is_delim(*str, delim))
			{
				// malloc with error check
				overall_array[array_seg_index] = malloc(1); // just space for '\0'
				if (!overall_array[array_seg_index])
				{
					// free everything allocated so far
					while (array_seg_index--)
						free (overall_array[array_seg_index]);
					free (overall_array);
					return (NULL);
				}

				// allocate 
				overall_array[array_seg_index][0] = '\0'; // complete current seg

				array_seg_index++; // prepare for next seg
				str++;							// then increment to next char
			}
		}
		// transition: delim > seg
		// handling non-empty segs
		else if (!is_delim(*str, delim) && is_delim_flag)
		{
			is_delim_flag = 0; // state update

			ptr_trail = str;	// mark start of next seg

			while (*str && !is_delim(*str, delim))
				str++; // bring str pointer to end of segment

			// allocate & store seg
			int	len = str - ptr_trail;
			overall_array[array_seg_index] = malloc(sizeof(char) * (len + 1));
			if (!overall_array[array_seg_index]) // if more time, would break this out into helper
			{
				// free everything allocated so far
				while (array_seg_index--)
					free (overall_array[array_seg_index]);
				free (overall_array);
				return (NULL);
			}
			// copy seg
			int	i = 0;
			while (i < len)
				overall_array[array_seg_index][i++] = *ptr_trail++;

			overall_array[array_seg_index][i] = '\0';

			array_seg_index++;
			continue; // skip str++ at end of loop (double increment) as already at end of segment
		}
		str++;
	}
	return (overall_array);
}
