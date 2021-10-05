// String With Difference Of Every Two Consecutive Characters

// 1. You are given a string that contains only lowercase and uppercase alphabets. 
// 2. You have to form a string that contains the difference of ASCII values of every two consecutive characters between those characters.
//    For "abecd", the answer should be "a1b3e-2c1d", as 
//    'b'-'a' = 1
//    'e'-'b' = 3
//    'c'-'e' = -2
//    'd'-'c' = 1

// Input Format
// A String

// Output Format
// A String

// Constraints
// 1 <= length of string <= 1000

// Sample Input
// pepCODinG

// Sample Output
// p-11e11p-45C12O-11D37i5n-39G

#include <iostream>
#include <string>
using namespace std;

string diff(string s){

	string ss="";
	ss += s[0];

	for(int i=1; i<s.length(); i++){

		int gap = s[i] - s[i-1];

		ss += to_string(gap);
		ss += s[i];
	}

	return ss;
}

int main(){

	string s;
	cin >> s;

	cout << diff(s) << endl;
	return 0;
}