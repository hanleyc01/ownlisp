#include "mpc.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h> // standard library
#include <editline/readline.h> // read input allowing editing
#include <readline/history.h> // record history of inputs with up and down arrows

/* Counting the number of expressions in the tree;
 * an expression is either a number, or an operator plus an expression*/ 
int tree_leave(mpc_ast_t* t) {
	int leaves = 0;
	if (strstr(t->children[0]->tag, "number")) {
		leaves++;
	}
	return leaves;
}

/* Use strcmp() to directly equate two strings and determine 
 * if it is some operator */
long eval_op(long x, char* op, long y) {
	if (strcmp(op, "+") == 0) { return x + y; }
	if (strcmp(op, "-") == 0) { return x - y; }
	if (strcmp(op, "/") == 0) { return x / y; }
	if (strcmp(op, "*") == 0) { return x * y; }
	if (strcmp(op, "%") == 0) { return x % y; }
	return 0;
}

/* Determine which operator to use, 
 * and checking if tag conatins some substring
 * */
long eval(mpc_ast_t* t) {

	// Checking to see if tag is number, if so return
	// immediately
	if (strstr(t->tag, "number")) {
		// strstr checks for substring, think .contains()
		return atoi(t->contents);
	}

	// Operator is always the second child
	char* op = t->children[1]->contents;
	//			^checks first child of node
	//						 ^ and looks at its contents
	
	// Descent to the number
	long x = eval(t->children[2]);

	// Iterate over the remaining children and combining
	int i = 3;
	while (strstr(t->children[i]->tag, "expr")) {
		x = eval_op(x, op, eval(t->children[i])); // recursive descent
												  // down the tree
		i++;
	}

	return x;
}

int main(int argc, char** argv) {
	
	/* Create some new parsers */
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* String = mpc_new("string");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lispy = mpc_new("lispy");

	/* Definitions in default language */ 
	mpca_lang(MPCA_LANG_DEFAULT,
		"																				\
			number	 : /-?[0-9]+/ ;														\
			string	 : /[ab]+/ ;														\
			operator : '+' | '-' | '*' | '/' | '%' ;									\
			expr	 : <number> | '(' <operator> <expr>+ ')' ;							\
			lispy	 : /^/ <operator> <expr>+ /$/ ;										\
		",
		Number, String, Operator, Expr, Lispy);
	
	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while (1) {

		char* input = readline("lispy> ");
		
		/* Attempt to call and parse user input */ 
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			long result = eval(r.output);
			
			mpc_ast_print(r.output);

			printf("The number of leaves in this tree is: %i\n", tree_leave(r.output));

			printf("%li\n", result);
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}
	}

	/* Cleanup code */ 
	mpc_cleanup(4, Number, Operator, Expr, Lispy);

	return 0;
}
