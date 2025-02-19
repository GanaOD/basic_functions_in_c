# 1. Quick natural language reasoning:

2 main passes through string:
	1: determine nr. of segments: for overall array of arrays (overall_array)
		int	seg_count, initialised to 0
	2: malloc & store each array (segment_str)


2nd pass:

while in a segment: 
	create pointer window:
		ptr_lead moves to last char
		ptr_trail remains at 1st char
	malloc space for this segment
	copy over using ptr_trail for allocation of each char > segment_str


overall delim-logic:
	if delim encountered, create empty segment_str (handles leading & trailing delims)

multiple consecutive delims:
	only 1 new empty string, don't process following delims


Meaning for 1st pass:
	if we encounter a delim: to ensure proper handling of multiple:
		- could peek ahead to next char. if also delim, just move forwards, don't increase seg_count any further
		- state machine: introduce is_delim flag. set to 1 when is_delim true, set to 0 when is_delim false. 
				could use this to determine seg_count & organise logic in 2nd pass



# 2. Mapped to a formal computational abstraction: finite state machine
	with clear state transitions


### State machine moving through str: get segment count for memory allocation

State 0: Outside Segment (is_delim = 1)
  │
  ├─── see non-delim → increment seg_count, switch to State 1
  │
  └─── see delim → stay in State 0 (handles multiple delims)

State 1: Inside Segment (is_delim = 0)
  │
  ├─── see delim → switch to State 0
  │
  └─── see non-delim → stay in State 1


### 2nd pass: store segments

2 ptrs create window:

"apple,banana,orange"
 ^   ^
 |	 ptr_lead
 ptr_trail       

ptr_lead advances until delimiter or end
then we have our substring bounds



# NB

Re. what appeared to be 2 methods in initial reasoning:
actually the same fundamental logic viewed at different levels of abstraction:

"check chars and move"          "state machine"
─────────────────────    =    ──────────────────
if (is_delim)                 State 0 (outside)
  skip                          ↓
else                         State 1 (inside)
  process


state machine isn't a different method - it's a higher-level formalization that makes the underlying pattern explicit. 
reveals the essential structure: always tracking whether we're inside or outside a segment, regardless of implementation



# States & boundaries:
                  
Outside (is_delim = 1)
│                    
├──── *str == 0     → END (string finished)
│
└──── !is_delim     → Inside (found start of segment)

Inside (is_delim = 0)
│
├──── *str == 0     → END (string finished mid-segment)
│
└──── is_delim      → Outside (hit delimiter)


translates to implementation boundary checks:

while (*str && ...)     // Primary guard: are we still in string?
    if (!is_delim...)   // State transition check


The && in conditions ensures I never:
	Access memory beyond string end
	Miss a state transition
	Process wrong characters

Each state needs both:
	Continuation condition (still in string?)
	State transition check (should we switch states?)



# nested code structure

that naturally emerges:

while-if-while:
	Maintain overall progress (while (*str)) - global progress/state
	Detect transitions (if is_delim(char) doesn't match is_delim_flag)
	Process states until boundaries - local processing





Idea:
	seg_count in 2nd pass
		compared with seg_count from 1st pass to verify
		if !=, free overall_array: sth. went wrong