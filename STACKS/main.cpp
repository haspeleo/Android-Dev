/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 31 mars 2011, 16:55
 */

#include <cstdlib>

#include "Stack.h"

using namespace std;

/*
 * Stack Manipulation
 */
int main(int argc, char** argv) {

	Stack<int> s;
	for (int i = 0; i < 10; i++) {
	s.push(i);
	}
   	s.pop();

    return 0;
}

