# Pattern
Key insight
any number can be uniquely decomposed into a product of prime factors. 
This is the Fundamental Theorem of Arithmetic.

When we think about factorization, we can visualize it as repeatedly "extracting" the smallest possible divisors from a number until nothing remains but 1.


# Design Principles

Minimalism: 
We don't need to precompute primes because we can discover them in the process of factorization.

Natural Ordering: 
By starting with the smallest possible factor (2) and incrementing, we automatically get prime factors in ascending order.

Efficiency through Division: 
When we find a factor, we divide the number by it immediately, reducing the problem size.



# Reasoning Process

Consider factoring 60:

Try dividing by 2: 60 ÷ 2 = 30 (Factor found!)
Continue with 30, try 2 again: 30 ÷ 2 = 15 (Factor found!)
Continue with 15, try 2: 15 ÷ 2 = 7.5 (Not divisible)
Try 3: 15 ÷ 3 = 5 (Factor found!)
Continue with 5, try 3: 5 ÷ 3 = 1.67 (Not divisible)
Try 4: 5 ÷ 4 = 1.25 (Not divisible)
Try 5: 5 ÷ 5 = 1 (Factor found!)
Result is 1, we're done: 2 * 2 * 3 * 5

why did we try 4? It's not prime. 
This is where an insight emerges: we don't need to check if our factors are prime because composite numbers will never be factors if we work in ascending order.
Why? By the time we reach a composite number (like 4), its prime factors (2*2) would have already divided the number if they could. 
This is a beautiful mathematical property that simplifies our algorithm.




void fprime(char *str)
{
    int num = atoi(str);
    int factor = 2;
    int first_factor = 1;
    
    if (num == 1)
    {
        printf("1");
        return;
    }
    
    while (num > 1)
    {
        if (num % factor == 0)
        {
            if (first_factor)
                first_factor = 0;
            else
                printf("*");
            
            printf("%d", factor);
            num /= factor;
        }
        else
            factor++;
    }
}





# Implementation Logic

Start with the smallest prime (2)

If the current factor divides the number:
	Output the factor (with separator if not first)
	Divide the number by this factor
	Continue with the same factor (don't increment yet)

If the current factor doesn't divide:
	Increment the factor and try again

Stop when the number reaches 1




This approach is elegant because:

It doesn't require precomputing prime numbers or storing them
It finds factors in ascending order naturally
It handles prime inputs correctly (they're just printed as is)
It's efficient because it divides by each factor as many times as possible before moving to the next




# Implementation steps

#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	// don't need str param error check !str 
	// or check whether str contents (chars) are valid
	// these both guaranteed by subj

	int	nbr = atoi(str);

	if (nbr == 1)
		printf("1"); return ;
	
	int	factor = 2;
	int	first_factor = 1;

	while (nbr > 1)
	{
		if (nbr % factor == 0)
		{

		}
		else factor++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}


Need sth. to manage output formatting, hence first_factor flag


# first_factor flag: output formatting

The first_factor variable is a flag that helps us manage the formatting of the output, specifically when to print the "*" separator between factors.


We initialize first_factor = 1 (true) at the beginning.
When we find our very first factor, we want to print just the number without any "*" prefix.
For all subsequent factors, we need to print "*" before printing the factor.


So the logic works like this:

	When we find a factor, we check if it's the first one (if (first_factor))
	If it is the first factor, we set first_factor = 0 (false) and don't print a "*"
	If it's not the first factor, we print a "*" before the number
	Then we print the factor itself with printf("%d", factor)


For example, with 60:

	First factor is 2: prints "2" (no "*"), sets first_factor = 0
	Second factor is 2: prints "*2"
	Third factor is 3: prints "*3"
	Fourth factor is 5: prints "*5"

Final output: "223*5"


a one-time switch that transitions from "first factor" to "subsequent factors" mode. Once it's turned off (set to 0), it stays off for the remainder of the function execution.
These kinds of simple patterns in code are elegant precisely because they accomplish exactly what's needed with minimal complexity