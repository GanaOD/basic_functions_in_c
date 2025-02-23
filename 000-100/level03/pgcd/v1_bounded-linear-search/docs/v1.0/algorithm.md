reducing search space:

Since we want the highest common divisor, we can start from the smaller number and work down
As soon as we find a number that divides both inputs, that's our answer
This is more efficient than starting from 1 and working up


mathematical pattern of searching downwards:
Consider two numbers a and b where a > b

Any common divisor of a and b must also divide their difference (a - b)
This is because if d divides both a and b:

a = md for some m
b = nd for some n
a - b = (m-n)d


This insight leads to the Euclidean algorithm




think about the mathematical structure:

Starting condition:
	We find min(i1, i2) - this is our upper bound
	We know our answer must be >= 1 (termination point)

Then we're stepping through potential divisors in descending order:
	For each number k from min(i1,i2) down to 1
	First number that divides both i1 and i2 is our answer

So we can describe this as:
	A bounded linear search
	The bound is [1, min(i1,i2)]
	Searching downwards through this interval
	The first match is guaranteed to be the highest common divisor
	We're guaranteed to find at least 1 as a common divisor



# Check-then-act

while (divisor >= 1)  // include 1 in our check
{
    if ((i1 % divisor == 0) && (i2 % divisor == 0))
        return divisor;  // first found is highest
    divisor--;
}

same functionality here, but more elegant?:

while (divisor > 0)  // more natural boundary for positive integers
{
    if ((i1 % divisor == 0) && (i2 % divisor == 0))
        return divisor;
    divisor--;
}

Both versions handle the case where 1 is the GCD, but the second one expresses the natural boundary of our domain (positive integers) more clearly


This is about understanding control flow and termination conditions in algorithms. Let's analyze the pattern:
When working with descending sequences and termination conditions, there are generally two approaches:

1. Check-then-act:
	Test condition at loop start
	Only enter loop if condition met
	Last value that passes check is the one processed


2. Act-then-check:
	Process value first
	Then check if should continue
	Can use do-while for this pattern



In our case, we're using pattern 1, where our while condition divisor > 0 acts as a guard, but importantly, the last valid value (1) gets processed through our divisibility check before any further decrement. The return statement creates an early exit point that preserves the current value of divisor when we find our answer.


This pattern is particularly clean for algorithms where:
	We need to test values in sequence
	The first valid result we find is our answer
	We have a known valid termination value (like 1 for GCD)



# insight

something fundamental about programming: the difference between mathematical abstraction and computational implementation.
In pure mathematics, we can say "GCD is the largest positive integer that divides both numbers" - a declarative definition.

But in a program, we have to carefully consider:
	Control flow paths
	Boundary conditions
	When and in what order operations happen
	Where values are captured/returned

A single off-by-one error in these implementation details can make a mathematically correct algorithm fail in practice. This is why understanding these patterns deeply - like how loop termination interacts with when we check/process values - is crucial for reliable programming.






# HIGH LEVEL

Algorithm Description:
It's a "Bounded Linear Search" or "Descending Linear Search" for the Greatest Common Divisor (GCD)
Starting from the smaller of the two numbers
Testing each potential divisor from highest to lowest until finding one that divides both numbers
Mathematically: Finding the largest k where k|a and k|b (k divides both a and b)

This is an intuitive but inefficient approach - O(n) complexity where n is the smaller input number.