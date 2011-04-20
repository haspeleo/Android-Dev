
/*
 * http://www.site.uottawa.ca/~lucia/courses/2131-05/labs/Lab3/CommandLineArguments.html
 */


#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

int x = atoi(argv[1]);
int y = atoi(argv[2]);

cout <<x<<y<<endl;

return 0;
}
