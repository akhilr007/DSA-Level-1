// Print Subsequence

// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.
// Use sample input and output to take idea about subsequences.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A string str

// Output Format
// Subsequences of str in order hinted by Sample output

// Constraints
// 0 <= str.length <= 7

// Sample Input
// yvTA

// Sample Output
// yvTA
// yvT
// yvA
// yv
// yTA
// yT
// yA

#include <iostream>
#include <string>
using namespace std;

void printSS(string str, string op){

	if(str.length() == 0){
		cout << op << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	// ch - yes choice
	printSS(ros, op+ch);
	// ch - no choice
	printSS(ros, op);
}

int main() {

	string str;
	cin >> str;

	printSS(str, "");
	return 0;
}