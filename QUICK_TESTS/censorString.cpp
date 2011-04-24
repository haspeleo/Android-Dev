#include <iostream>
#include <string>

using namespace std;

string censorString(string text, string remove) {

      string result = "";
      for (int i = 0; i < text.length(); i++)
      {
            bool found = false;
            for (int k = 0; k < remove.length(); k++)
            {
                  if (text[i] == remove[k])
                  {
                        found = true;
                        break;
                  }
            }
            if(!found)
            {
                  result += text[i];
            }
      }
      return result;
}





/*
    string str = "";
    int textSize = text.length();
    int removeSize = remove.length();

    for(int i = 0; i < textSize; i++) {

        int j = 0; //removeSize;
                cout<<"i = "<<i<<endl;
                cout<<"j = "<<j<<endl;
        while(j < removeSize) { //> 0) {
            if(text[i] == remove[j]) 
                j = removeSize + 1;
                else
                j ++; //--;
        }

        if(j < removeSize) //j <= 0)
        str += text[i];
       }
return str;
}
*/

int main() {

string  text = "stanford";
string remove = "nt";

string output = censorString(text, remove);

cout <<"After censoring : "<<output<<endl;




return 0;

}
