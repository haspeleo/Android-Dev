/*
 * Many compilers offer an assert() macro. The assert() macro returns TRUE if
 * its parameter evaluates TRUE and takes some kind of action if it evaluates FALSE.
 * Many compilers will abort the program on an assert() that fails; others will throw an exception

 * One powerful feature of the assert() macro is that the preprocessor collapses it
 *  into no code at all if DEBUG is not defined. It is a great help
 * during development, and when the final product ships there is no performance
 * penalty nor increase in the size of the executable version of the program.

 * Rather than depending on the compiler-provided assert(), you are free to write
 * your own assert() macro.
 * Listing below provides a simple assert() macro and shows its use.
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//ASSERTS
#define DEBUG



int main(int argc, char** argv) {

    return 0;
}

