/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 7 mars 2011, 13:42
 */

#include <fstream>

using namespace std;


int main(int argc, char** argv) {

    ofstream SaveFile("cpp-home.txt");
    SaveFile << "Hello world, from www.cpp-home.com";
    SaveFile.close();

    return 0;
}

