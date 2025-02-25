# Research

https://42-cursus.gitbook.io/guide/exams/exam-rank-02/level-4/flood_fil

https://leetcode.com/problems/flood-fill/description/

https://www.geeksforgeeks.org/flood-fill-algorithm/


# Brainstorming

## Queue-based approach
	more robust


Key differences from recursive approach:

Memory efficiency: Instead of deep recursion, we maintain a queue of points to process
Stack safety: No risk of stack overflow as we're using heap memory
Performance: Potentially faster as we avoid function call overhead


## Recursive approach

Small grid sizes in exam, so recursive approach ok

Key insights:

Base cases (return conditions) stop the recursion when:

Out of bounds
Hit different character
Already filled ('F')


Each position is visited exactly once
The flow naturally follows connected regions


### My choice: Depth-First Search (DFS)

Stack Evolution (depth first):
[2,2]              START HERE
  └─[2,1]          GO LEFT FIRST
     └─[1,1]       THEN UP FROM THERE
        └─[0,1]    KEEP GOING UP UNTIL CAN'T
     └─[2,0]       TRY OTHER DIRECTIONS...
  
  When this left branch is exhausted:
[2,2]              BACK TO START
  └─[1,2]          NOW TRY UP
     └─[1,3]       ...and so on


like exploring a cave system:

(2,2) START
               │
        ┌──────┴──────┐
     Left          Right
      │              │
   ┌──┴──┐       ┌───┴───┐
  Up   Down     Up     Down

Each "path" must be fully explored before backtracking. The stack grows deeper only when we find a valid cell to fill, and shrinks as we exhaust all options at that position.



### Visual flow of execution:

Current (x)    Steps:
1 1 1 1        1. Fill current 'x' with 'F'
1 0 0 1        2. Check all 4 neighbors:
1 0 0 1           └── Up: in bounds & matches? → New t_point
1 1 1 1           └── Down: in bounds & matches? → New t_point
                  └── Right: in bounds & matches? → New t_point
                  └── Left: in bounds & matches? → New t_point

**Advantages:**
Uses t_point consistently (more type-safe)
Boundary checks are explicit for each direction
No need for separate target variable (saved in c)


**Disadvantages:**
More memory operations (creating new t_point for each recursive call)
More verbose due to t_point struct creation
Four separate if blocks instead of unified checks





### visualisation of memory during recursion:

The call stack grows like a vertical tower, where each "floor" (stack frame) contains:

Stack grows downward:

[main()]                  Top of Stack
   │
[flood_fill()]
   │
[fill(2,2)]  ← Initial call
   │
[fill(1,2)]  ← Checking up
   │
[fill(1,3)]  ← Checking right
   │    
[fill(1,1)]  ← Checking left
   │
   ▼         Bottom of Stack




Each stack frame contains:

Local variables (row, col coordinates)
Return address (where to go back to)
Parameters passed in

Single Stack Frame:
┌────────────────────┐
│ Return Address     │
├────────────────────┤
│ Parameters:        │
│  - tab            │
│  - size           │
│  - target         │
│  - row            │
│  - col            │
├────────────────────┤
│ Local Variables    │
└────────────────────┘

we don't need to explicitly store a graph structure - the stack implicitly maintains our "path" through the grid. As each recursive call returns, we automatically backtrack to the previous position.




**recursive helper fill function**

A recursive function is one that solves a problem by:
   Calling itself
   With a simpler version of the same problem
   Until it hits a base case


In my fill function:
   Base cases: out of bounds or cell doesn't need filling
   Recursive step: fill current cell and call itself on neighbors
   Problem gets simpler because marking cells as 'F', so each cell can only be processed once

doing the recursive work while flood_fill just sets up the initial conditions.