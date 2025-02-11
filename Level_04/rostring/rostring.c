#include <unistd.h> // for write
#include <stdlib.h> // malloc
#include <stdio.h> // printf debug statements

int is_space(char c)
{
  return (c == ' ' || (c >= 9 && c <= 13));
}

char  *store_word(char *str, int len)
{
  char  *word = malloc(len + 1);
  int   i = 0; // index for copying

  while (i < len)
  {
    word[i] = str[i];
    i++;
  }
  word[i] = '\0';

  printf("Debug: word to be stored: %s\n", word);

  return (word);
}

void  rostring(char *str)
{
  char  *first_word;
  int   len = 0;
  int   first_printed = 0;

  // handle leading space
  while (is_space(*str))
    str++;
  
  printf("Debug: Handled leading space\n");

  while (str[len] && !is_space(str[len]))
    len++;
  if (!len)
    return;
  printf("Debug: len of first word = %d\n", len);

  first_word = store_word(str, len);
  
  // move str pointer to 1 after first word to continue overall incrementation
  str += len;
  
  // Handle rest of string
  while (*str)
  {
    // 2 conditions
    if (is_space(*str))
    {
      while (is_space(*str))
        str++; // increment through all spaces
      if (*str && first_printed) // if not end of string
        write (1, " ", 1); // write 1 space 
    }
    else
    {
      write (1, str++, 1);
      first_printed = 1;
    }
  }
  // space between last word processed in str and the final word (stored)
  if (first_printed)
    write (1, " ", 1);

  write (1, first_word, len);
  free (first_word);
}


int main(int ac, char **av)
{
  if (ac > 1)
    rostring(av[1]);
  write (1, "\n", 1);
  return (0);
}