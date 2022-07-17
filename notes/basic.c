#include <stdio.h>

// C programs consist of structures and functions, and that's it!

// #define can be used to declare global constants
#define WIDTH = 10;
#define HEIGHT = 20;

typedef struct {
	int width;
	int height;
} rectangle;

rectangle init_rect(int w, int h) {
	rectangle r;
	r.width = w;
	r.height = h;
	return r;
}

// typedef differs from #define
typedef unsigned char BYTE;

typedef struct {
	float x;
	float y;
} point;

// We can declare and initialize structures, though this is purely
// conventional!
point init_point(int x, int y) {
	point p;
	p.x = x;
	p.y = y;
	return p;
}

// Functions manipulate variable arguments
int foo(int x) {
	return x + 1;
}

// Some different primitive types:
// void: empty type (like unit),
// char: a single byte,
// int: 32-bit integers,
// long: 64-bit integers,
// float: 32-bit decimal number,
// double: 64-bit decimal number

int main(int argc, char** argv) {
	int count = 0;
	int return_value = foo(count);

	// Strings are interesting in that they are
	// pointers to characters; they contain characters
	// as well as a null-terminator at the end of the string;
	char* str = "Hello, world!";
	puts(str);
	printf("Return value of foo: %d\n", return_value);
	
	return 0;
}
