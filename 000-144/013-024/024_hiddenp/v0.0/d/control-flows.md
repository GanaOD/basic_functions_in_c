# Overall understanding;

for each char in s1: check if there's a match in s2
if there is, move to next char in s1
if there is a match in s2, the incrementing in a loop continues from 1 after the position of the previous match - due to order rule

success when end of s1 reached
if s2 ends before s1, return 0



## match-focused (original attempt):


while (*s2)
{
    if (*s2 == *s1)  // When we find a match
        s2++, s1++;   // Move both forward
    s2++;            // Only s2 moves if no match
}

Primary loop on s2 (searching space)
would have needed additional logic to handle reaching end of s2 before s1

"Walk through the haystack, note when each needle piece found"


## non-match-focused

while (*s1)          // Focus on completing s1
{
    while (*s2 && *s2 != *s1)  // Skip non-matches
        s2++;
    if (!*s2)        // Hit end of s2 without match
        return fail;
    s1++, s2++;      // Found match, advance both
}

Primary loop on s1 (pattern to find)
naturally handles case: reaching end of s2 before s1 in the if (!*s2) check

"For each needle piece, scan the haystack until found"


## to help myself visualise:

person scanning a crowd looking for a sequence of friends wearing specific colored shirts

Looking for sequence: [🔴, 🔵, 🟢]
Crowd: [👕, 👕, 🔴, 👕, 🔵, 👕, 👕, 🟢]


"non-match" / negative check approach:

"I need 🔴 first" -> "Nope, nope, YES!" 
                                ↓
"Now I need 🔵"  -> "Nope, YES!"
                            ↓
"Finally need 🟢" -> "Nope, nope, YES!"


always in a state of "I need X" and skip everything else. This creates a more focused search pattern

while (*s1)          // "I need this character"
{
    while (*s2 && *s2 != *s1)  // "Skip until I find it"
        s2++;


fail fast