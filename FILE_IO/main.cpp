/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 7 mars 2011, 13:42
 * http://www.cpp-home.com/archives/67.htm
 */

#include <fstream>
#include <iostream>



using namespace std;
void readFile(ifstream &file) {
    
    char ch;
    while(!file.eof()) {
        file.get(ch);
        cout << ch;
    }   
}

/**************************************************************************/
/*                 MAIN PROGRAM                                           */
/**************************************************************************/
int main(int argc, char** argv) {

    fstream File("cpp-home.txt", ios::in | ios::out);
    File << "Hello wold, fstream !"; //put "Hi!" in the file
    static char str[10]; //when using static, the array is automatically
    //initialized, and very cell NULLed
    File.seekg(ios::beg); //get back to the beginning of the file
    //this function is explained a bit later
    File >> str;
    cout << str << endl;
    File.close();

    ifstream OutFile("cpp-home.txt");
    char ch;
    char line[100];
    while (!OutFile.eof()) {
        OutFile.getline(line, 100); //printing lines instead of characters
        //OutFile.get(ch);
        cout <<line<<endl;
        //cout <<ch<<endl;
    }
    return 0;
}

