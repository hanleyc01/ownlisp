#include <stdio.h>
#include <stdlib.h> // standard library
#include <editline/readline.h> // read input allowing editing
#include <readline/history.h> // record history of inputs with up and down arrows

/* This is just a basic read-input, echo back input,
 * but it will be helpful in understanding conceptually
 * what a repl is.
 * */

int main(int argc, char** argv) {

	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while (1) {
		
		// Output prompt to get input
		char* input = readline("lispy> ");

		// Add input to history
		add_history(input);

		// Echo input
		printf("No you're a %s\n", input);

		// Free retrieved input
		free(input);
	}

	return 0;
}
