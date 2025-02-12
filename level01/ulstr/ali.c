// Bit manipulation
// More idiomatic C using the fact that ASCII uppercase and lowercase 
// letters differ only in the 6th bit (0x20)

char swap_case_bits(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return c ^ 0x20;
	return c;
}


/*
Uses the fact that uppercase and lowercase letters in ASCII differ by exactly one bit (bit 5, value 32 or 0x20)
XOR operation (^) with 0x20 toggles this bit, effectively swapping case
This is both elegant and efficient - no branching needed for the actual swap
Visual insight: Think of letters as binary patterns where flipping just one bit changes their case

*/