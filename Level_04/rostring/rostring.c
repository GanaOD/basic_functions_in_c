#include <unistd.h> // for write

int in_word(char c)
{
  if (c == ' ' || c >= 9 && c <= 13)
    return (0);
  else 
    return (1);
}

while (*str)
{
    // Handle initial spaces
    if (!in_word(*str) && in_word_flag == 0)
        str++;
    // Find & store first word
    else if (in_word(*str) && in_word_flag == 0)
    {
        // First word logic...
        
        // Then immediately try to handle rest of string?
        if (!in_word(*str) && in_word_flag == 1)
        {
            // Next word logic...
        }
    }
}

