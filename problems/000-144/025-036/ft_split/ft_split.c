#include <stdlib.h>
#include <stdio.h>

// in_word: sensor/detector, provides "trigger conditions" for in_word_flag: 
// returns 1 if in a word, returns 0 if outside a word (i.e. in a space)
int in_word(char c)
{
    // if c is outside a word, i.e. in a space
    if (c == ' ' || (c >= 9 && c <= 13))
        return (0);
    
    // Assuming we'll otherwise only encounter ascii chars that represent alphabetical letters
    return (1);
} 



void    cleanup_words(char  **words)
{
    char **original = words;  // Keep track of start in order to free containing structure 
    while (*words)
        free(*words++);
    free(original);          // Free from original position
}




/* 
Word-processing functionality helper
    - takes pointer-window from main word traversal (2nd pass)
    - Calculates length of word
    - Allocates memory
    - Copies to malloced memory
*/
char    *process_word(char *ptr_lead, char *ptr_trail)
{
    int     len = ptr_lead - ptr_trail;
    char    *word = malloc (sizeof(char) * (len + 1));
    if (!word)
        return (NULL);

    // ptr for writing into new memory
    char    *ptr_write = word;

    // Copying logic
    while (ptr_trail < ptr_lead)
        *ptr_write++ = *ptr_trail++;

    // NULL terminate string
    *ptr_write = '\0';

    return (word);
}




// Main ft_split function:
// Maintains full control over array structure, where things are stored etc.

char    **ft_split(char *str)
{
    // 1st pass through string: count number of words
    // Using state machine
    char    *ptr_lead = str;
    int     in_word_flag = 0; // track state change (word boundaries): memory
    int     word_count = 0;

    while (*ptr_lead)
    {
        if (in_word(*ptr_lead) && !in_word_flag) // just moved into a new word
        {
            word_count++;
            in_word_flag = 1;
        }
        else if (!in_word(*ptr_lead))
            in_word_flag = 0;
        ptr_lead++;
    }


    // 1st allocation phase: array of pointers (later pointed to each individual word / str / char *)
    char    **words = malloc(sizeof(char *) * (word_count + 1));

    if (!words)
        return (NULL);


    // 2nd pass through string: word processing - each word gets space allocated & is then copied over

    // Sliding window: 
    // making use of state machine logic from 1st pass
    //      - ptr_lead iterates through first word. When it moves into a space (!in_word but in_word_flag still 1), before continuing to iterate through space with in_word_flag = 0, process this first word
    //      - once this word has been processed, ptr_lead moves through space(s) to next word. When it points to 1st char of new word, set ptr_trail to this position, ensure state change & iterate through, repeating previous stage of process
    // Overall condition: this repeats until end of str (while (ptr_lead))

    // Reset
    ptr_lead = str; 
    in_word_flag = 0;

    // Introduce now for sliding window
    char    *ptr_trail = str;

    // HOW TO DESCRIBE ROLE OF THIS VARIABLE?
    char **current_word = words;


    while (*ptr_lead)
    {
        if (in_word(*ptr_lead) && !in_word_flag)
        {
            ptr_trail = ptr_lead;  // Mark start of word
            in_word_flag = 1;
        }
        else if (!in_word(*ptr_lead) && in_word_flag)
        {
            *current_word = process_word(ptr_lead, ptr_trail);
            if (!current_word)
            {
                cleanup_words(words);
                return (NULL);
            }
            current_word++;
            in_word_flag = 0;
        }
        ptr_lead++;
    }
    // Store ptr to newly allocated word into current slot of our array of strings (words): this is how we build the array of strings: each "slot" gets progressively filled with a ptr to a newly allocated word


    // Once we've copied a word into its allocated memory and stored the pointer in words, we can move on with ptr_lead and ptr_trail in the main string - we don't need to keep track of the original positions.


    // handle last word if string ends while in word - BECAUSE OTHERWISE CURRENT_WORD COUNT AND ESP. WORD PROCESSING ONLY HAPPENED WHEN WE EXITED A WORD AND MOVED INTO SPACE?
    if (in_word_flag)
    {
        *current_word = process_word(ptr_lead, ptr_trail);
        if (!current_word)
        {
            cleanup_words(words);
            return (NULL);
        }
        current_word++;
    }

    // NULL terminate array
    *current_word = NULL;

    return (words);
}


int main(int argc, char **argv)
{
    printf("String before split: %s\n", argv[1]);
    
    // No format specifier that can handle char ** 
    // In C, arrays are not first-class objects that carry their own metadata about length or structure
    // Therefore manual handling: must iterate through array of strings, printing each str individually
    char **result = ft_split(argv[1]);
    printf("String after split:\n");
    
    while (*result)
        printf("%s\t", *result++);

    return (0);
}




