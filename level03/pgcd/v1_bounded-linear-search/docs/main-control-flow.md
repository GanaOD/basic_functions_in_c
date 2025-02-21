# Original version:

// pgcd function: printf("%d", divisor);
int main(int ac, char **av)
{
    if (ac == 3)
        pgcd(av[1], av[2]);
    write(1, "\n", 1);  // This happens after pgcd
    return (0);
}

a familiar structure to other mains I've written

From a boolean logic perspective:
	We have a single condition (ac == 3)
	The newline is ALWAYS written, regardless of the condition
	This creates an elegant unification of two different cases


From a set theory view:
	Let S be the set of all possible argument counts
	We have effectively partitioned S into:
		{3} - where we compute pgcd AND write newline
		S - {3} - where we only write newline


From a functional perspective:
	f(x) = { pgcd() + newline  if x = 3
	{ newline           if x ≠ 3



This approach satisfies both requirements from the subject:
	"If the number of parameters is not 2, display a newline"
	The need for a newline after successful pgcd computation

It's a minimal solution that handles all cases with a single control flow structure.




PROBLEM:
a newline written before result in stdout




# new version 


// pgcd function: printf("%d\n", divisor);

int main(int ac, char **av)
{
    if (ac != 3)
        write(1, "\n", 1);
    else
        pgcd(av[1], av[2]);
    return (0);
}

The key difference is in the timing and ordering of operations. 
In the original version, even though logically we want the newline right after the number, the write call was actually happening separately and possibly getting flushed to output at a slightly different time, creating that visual gap.
In the new version, the newline is part of the same printf operation, ensuring it's buffered and output together with the number, giving us the clean output we want.
This is a good example of why understanding buffering and output stream behavior matters in C programming!




