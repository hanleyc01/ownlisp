# Evaluation of the Abstract Syntax Tree

- If we look inside `mpc.h`, we can see this struct
```
typedef struct mpc_ast_t {
  char* tag;
  char* contents;
  mpc_state_t state;
  int children_num;
  struct mpc_ast_t** children;
} mpc_ast_t;
```
- Whenever we printed out our results of the parsing, we got `operator|char:1:1 '+'` or `expr|number|regex:1:3 '3'`
- These are the tags, which are going to be important to see what parse rules we have to use to create the node

- Contents will contain the actual contents of the node

- State contains information about what state the parser was in when it found this node, such as the line and column number

- `children_num` and `children` are what allows us to traverse the tree, they tell is information about where to get next (and how many child nodes exist under this node)
	- The type of `children` is `mpc_ast_t**`, which is a pointer to a pointer — we can think of this as a list of the child nodes of a tree

- Because `mpc_ast_t*` exists as a pointer, the syntax for accessing its fields is a bit different, it follows the `->` notation, rather than `.` notation; thus it would be 
```
mpc_as_t* a = r.output;
prtinf("Tag: %s\n", a->tag); // rather than a.tag
```
