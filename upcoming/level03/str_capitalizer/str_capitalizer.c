#include <unistd.h>

/*
helper functions:
    Only care about character transformation rules
    Don't need to know position context
    Return transformed char (or same char if no transform needed)
*/

char    capitalize(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char    lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

/*
Handles string traversal logic
Single linear pass
Tracks word boundary state - just need to know whether at begin of word
Decides which helper to call
Handles output - direct write call
*/
void    str_capitalizer(char *str)
{
    int word_start = 1; // boolean flag

    while (*str)
    {
        if (*str != ' ' && *str != '\t')
        {
            if (word_start)
                *str = capitalize(*str);
            else
                *str = lowercase(*str);
            word_start = 0; // set flag > false when in word
        }
        else
            word_start = 1;
        write (1, str, 1);
        str++;
    }

}


int main(int ac, char **av)
{
    if (ac > 1)
        while (*++av)
            str_capitalizer(*av), write (1, "\n", 1);
    else
        write (1, "\n", 1);
    return (0);
}

