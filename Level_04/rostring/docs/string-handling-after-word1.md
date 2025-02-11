After handling leading space & storing 1st word:

while (*str)
  {
    // binary branching for 2 char classes: space & other chars
    if (is_space(*str))

    else
  }

What needs to happen? 

Move through all spaces, just write 1
write all chars directly with write call



What I've often done in while loops: 

have conditions apply to each char with a universal movement (incrementation through string done after checking all conditions & applying the logic of this specific condition to this specific char)



What I chose to do here:

create two self-contained "processing units" where each is responsible for both:
  The logic for its character type
  How far to move through the string

each condition "owns" its pointer movement because:
  Space handling: Needs to skip multiple spaces at once
  Character handling: Moves one by one while writing

More elegant than universal movement
Each condition fully handles its own "territory" - both processing and movement



Insight, seen more generally:
the granularity of processing (single-step vs multi-step) can be determined by the category of the element being processed, rather than imposed by a fixed-step traversal mechanism