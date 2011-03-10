#include <iostream>
#include <string>


using namespace std;

int findmatching(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    int position = -1;
    for (int i = 0; i < textLength - patternLength; i++) {
        int j = 0;
        while (j < patternLength && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == patternLength) position = i;
    }
    return position;

}

int main(){
    string text = "love you and only you";
    string pattern = "you";
    cout <<"TEXT: "<<text<<endl;
    cout <<"Fetching for pattern <"<<pattern<<">"<<endl;

    int position = findmatching(text, pattern);
        if (position)
                cout <<"pattern found at position : "<<position<<endl;
        else
                cout <<"pattern Not found!"<<endl;

return 0;
}
