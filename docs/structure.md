# level00: repository

problems

docs: 		meta-information on this repository




# level01 >> problems (numbered sub-directories)

Organisation: numerical
	more or less corresponding to order of first time working on problem
	
subdirectories:
	000-143			12^2 with sets of 12
	144-399			16^2 with sets of 16






# level02 : within a problem

these directories only created when branching occurs:

/d			docs

/g			ganaod: my work

/o			other work (person, organisation): alternative implementations 


INFO:

/d		doesn't exist if only including b file
			exists if I create meta-documentation across versions & person


/g 		doesn't exist if only my work included (default)







# level03

/d:
	b			brief / subject / specification / description:	problem to solve
	src		source


/o:
	/name/handle: 
	portions of code
	with documentation: analysis, insights gained...



(/g):


# level04: /v... (versions)

numbered

lower numbers: 
	likely beginning with v0 as 1st run through problem, probably struggling to work with ideas, concepts I've never encountered. Okay if low-quality hack that "just about works"
	lower nrs likely to be basic, simple: solutions that "get the job done", are "good enough"

later iterations:
	explorative, experimental
		exploring mathematics, computation, e.g. alternative, more advanced data structures & algorithms
		experimental: can be creative, try to find insightful solutions, good hacks
		advancing to, aiming for solutions that are mathematically pure & elegant, computationally advanced
	
		possible versions: (based off: purpose-principles...)
			security-hardened: apply security principles
			basic implementations in other languages
				
same number v0.0, 0.1 - same overall approach, algorithm...minor changes




# level05: within each /v:

s				solve: actual code

d				documentation:
						plan, design considerations
						reflection: insights, what I learned, theory: descriptions of ideas, concepts, theory...
						ideas for future exploration