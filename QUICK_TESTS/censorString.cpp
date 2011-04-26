/*
 *http://technical-interview.com/C_Questions_1.aspx
 * */
#include <iostream>
#include <string>

using namespace std;

string censorString(string text, string remove) {

	string result = "";
	for(int i = 0; i < text.length(); i++) {
		bool found = false;
		for(int j = 0; j < remove.length(); j++) {
			if(text[i] == remove[j]) {
				found = true;
				break;
			}
		}
	if(!found) {
		result += text[i];
	}


} 	

return result;
}



int main() {

	string  text = "stanford";
	string remove = "nt";
	
	string output = censorString(text, remove);
	
	cout <<"After censoring : "<<output<<endl;
	
return 0;

}
