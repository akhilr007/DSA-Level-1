// Print Encodings

// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
// Use the input-output below to get more understanding on what is required
// 123 -> abc, aw, lc
// 993 -> iic
// 013 -> Invalid input. A string starting with 0 will not be passed.
// 103 -> jc
// 303 -> No output possible. But such a string maybe passed. In this case print nothing.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A string str

// Output Format
// Permutations of str in order hinted by Sample output

// Constraints
// 0 <= str.length <= 10

// Sample Input
// 655196

// Sample Output
// feeaif
// feesf

#include <iostream>
#include <string>
using namespace std;

void printEncodings(string str, string psf){

	if(str.length() == 0){
		cout << psf << endl;
		return;
	}

	// if starting index element is 0, we cant proceed thereafter
	if(str[0] == '0'){
		return;
	}

	char ch0 = str[0]; // '5'
	char mchs = (char)((ch0 - '0') + 'a' -1); // mapping character of 5 which is e,, 5 - 0 + a - 1 = e

	string ros1 = str.substr(1);
	printEncodings(ros1, psf + mchs);


	if(str.length() >= 2){

		char ch1 = str[1];

		int u = ch1 - '0';
		int t = ch0 - '0';

		int val = t*10 + u;

		if(val <= 26){

			char mchp = (char)(val + 'a' -1);
			string ros2 = str.substr(2);

			printEncodings(ros2, psf + mchp);
		}
	}


}

int main() {

	string str;
	cin >> str;

	printEncodings(str, "");
	return 0;
}