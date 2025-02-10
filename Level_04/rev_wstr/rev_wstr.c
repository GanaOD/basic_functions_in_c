#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        write (1, "\n", 1);

    char    *ptr_end = argv[1];

    // Navigate to end of str & store beginning with argv[1]
    while (*ptr_end)
        ptr_end++;

    // Introduce leading pointer for pointer-window for main logic
    char    *ptr_lead = ptr_end;

    // Main logic: decrement through string, write each word directly
    while (ptr_lead > argv[1])  // Stop when we reach start
    {
        // Normal case: found a space
        if (*(ptr_lead - 1) == ' ')
        {
            write(1, ptr_lead, ptr_end - ptr_lead);
            write(1, " ", 1);
            ptr_end = ptr_lead - 1;
        }
        ptr_lead--;
    }
    // Handle first word (ptr_lead now at start)
    write(1, ptr_lead, ptr_end - ptr_lead);

    return (0);
}
