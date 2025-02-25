int is_power_of_2(unsigned int n)
{
    // Special case: 0 is not a power of 2
    if (n == 0)
        return 0;
    
    // Keep dividing by 2
    while (n > 1)
    {
			// If n is odd (has remainder when divided by 2), it's not a power of 2
			if (n % 2 != 0)
					return 0;
			
			// Divide n by 2 for next iteration
			n = n / 2;
    }
    
    // If we reach 1, it's a power of 2
    return 1;
}
