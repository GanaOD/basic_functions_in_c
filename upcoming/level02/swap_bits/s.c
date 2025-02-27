unsigned char swap_bits(unsigned char octet)
{
    // Step 1: Initialize variables to store the nibbles
    unsigned char higher_nibble; // Will hold the first 4 bits
    unsigned char lower_nibble;  // Will hold the last 4 bits
    unsigned char result;        // Will hold our final answer
    
    // Step 2: Get the higher nibble (first 4 bits)
    higher_nibble = octet / 16;
    // Dividing by 16 is equivalent to shifting right by 4
    // E.g., for 65 (0100 0001), higher_nibble = 4 (0000 0100)
    
    // Step 3: Get the lower nibble (last 4 bits)
    lower_nibble = octet % 16;
    // Modulo by 16 gets the remainder, which is the lower 4 bits
    // E.g., for 65 (0100 0001), lower_nibble = 1 (0000 0001)
    
    // Step 4: Put lower nibble in higher position
    result = lower_nibble * 16;
    // Multiplying by 16 is equivalent to shifting left by 4
    // E.g., 1 * 16 = 16 (0001 0000)
    
    // Step 5: Add the higher nibble to the lower position
    result = result + higher_nibble;
    // E.g., 16 + 4 = 20 (0001 0100)
    
    // Step 6: Return the swapped result
    return result;
}