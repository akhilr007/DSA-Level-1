// Print All Permutations Of A String Iteratively

// 1. You are given a string. 
// 2. You have to print all permutations of the given string iteratively.

// Input Format
// A String

// Output Format
// All permutations of the given string(one in a line). 


// Constraints
// 1 <= length of string <= 15

// Sample Input
// abc

// Sample Output
// abc
// bac
// cab
// acb
// bca
// cba

#include <iostream>
#include <string>
using namespace std;

int factorial(int n){

	int fact=1;
	for(int i=2; i<=n; i++){
		fact = fact*i;
	}
	return fact;
}
void printPermutations(string s){

	int n = s.length();
	int f = factorial(n);

	for(int i=0; i<f; i++){

		string ss = s;
		int temp = i;

		for(int div=n; div>=1; div--){

			int q = temp / div;
			int r = temp % div;

			cout << ss[r];
			ss.erase(ss.begin()+r);

			temp=q;
		}
		cout << endl;
	}
}

int main() {

	string s;
	cin >> s;

	printPermutations(s);
	return 0;
}