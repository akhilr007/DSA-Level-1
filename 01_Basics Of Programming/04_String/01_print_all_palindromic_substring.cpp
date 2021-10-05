// Print All Palindromic Substrings

// 1. You are given a string. 
// 2. You have to print all palindromic substrings of the given string.

// Input Format
// A String

// Output Format
// All palindromic substrings(one in a line).
// First, all palindromic substrings starting from first character of string will be printed, then from second character and so on.

// Constraints
// 1 <= length of string <= 500

// Sample Input
// abcc

// Sample Output
// a
// b
// c
// cc
// c

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){

	int lo = 0;
	int hi = s.length()-1;

	while(lo < hi){

		if(s[lo] != s[hi]) return false;

		lo++;
		hi--;
	}

	return true;
}

void printPalindromicSubstring(string s){

	for(int sp=0; sp<s.length(); sp++){

		for(int ep=1; ep<=s.length()-sp; ep++){

			string ss = s.substr(sp, ep);

			if(isPalindrome(ss) == true)
				cout << ss << endl;
		}
	}
}

int main(){

	string s;
	cin >> s;

	printPalindromicSubstring(s);
	return 0;
}