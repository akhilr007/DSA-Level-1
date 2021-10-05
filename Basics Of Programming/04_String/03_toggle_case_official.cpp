// Toggle Case

// 1. You are given a string that contains only lowercase and uppercase alphabets. 
// 2. You have to toggle the case of every character of the given string.

// Input Format
// A String

// Output Format
// A String

// Constraints
// 1 <= length of string <= 1000

// Sample Input
// pepCODinG

// Sample Output
// PEPcodINg

#include <iostream>
#include <string>
using namespace std;

void toggle(string s){

	for(int i=0; i<s.length(); i++){

		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = toupper(s[i]);
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = tolower(s[i]);
		}
	}

	cout << s << endl;
}

int main(){

	string s;
	cin >> s;

	toggle(s);
	return 0;
}