(After leading space handling)

while (str[len] && !is_space(str))
  len++;

if (!len) // If we found no chars before space/null
  return;

first_word = store_word(str, len);
str+=len; // Move past the word we just stored



# Switched to index notation
Prevents introduction of helper pointers



# Termination conditions
Originally only considered a subset of all termination conditions:
space 
where Word Termination Set = {space, tab, \0} (i.e. str could end after first word)


Complete Set vs Assumed Set

What I assumed: Word ends with space (subset)
Reality: Word ends with ANY terminator (complete set)


Boundary Detection Pattern

Need to detect ALL ways a sequence can end
Missing one = potential bug



# Two-Phase Operation Pattern:

Phase 1: Measurement (len counting)
[h][e][l][l][o][ ]...
 ^
len++ until terminator


Phase 2: Movement (str += len)
[h][e][l][l][o][ ]...
 ^---------------->
jump ptr by measured distance


Scout vs Mover pattern
Scout (len) measures the territory
Mover (str) uses scout's measurement to make one precise jump

separating:
Information gathering (measurement)
Action based on gathered info (movement)

more efficient than moving-while-measuring when I need the measurement for another purpose (like malloc)




Notation: operator overloading, compound assignment operators

str += len;

==

str = str + len;

==

while (len > 0)
    str++, len--;