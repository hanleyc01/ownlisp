# Context-free Grammars and Regular Expressions

- Noam Chomsky's great insight into linguistics was his formulation of language as being a combination of interchangeable elements;
- These can be formulated in a regular way, called *regular expressions*

```
.			Any character is required
a 			The character a is required
[abcdef]		Any character in the set from a to f is required
[a-f]			Any character in the range from a to f is required
a? 			The character a is optional
a*			Zero or more of the character a are required
a+ 			One or more of the character a are required
^			The start of the input is required
$			The end of the input is required
```
- Regular expressions is a really good tool for formalizing with precision, but it does not allow for variation
- Using a formalization, we can say that "a program is an operator followed by one or more expressions", where "an expression is either a number, or, in parentheses, an operator followed by one or more expressions"
	- This allows for encoding `(+ 3 2)` to `(* (3 + 3) + 2)`, or 
	```
	Program 		The start of the input, an Operator, one or more Expression, and end of input
	Expression 		Either a number, or in parentheses, an operator followed by one or more expressions 
	Operator  		'+', '-', '*', or '/'
	Number 			an optional '-', and one or more characters between 0 and 9
	```
- The library for formalizing our expressions, `mpc` uses `/ <expr> /` show the beginning and end of the program;
	- Thus, our program rule can be formalized as `/Operator?[0-9]+/`
- The result of this operation is an abstract syntax tree, which will then be evaluated by our compiler
	- The branches of the tree have all of the data we need to know about traversal and execution

