// String Compression

// 1. You are given a string. 
// 2. You have to compress the given string in the following two ways - 
//    First compression -> The string should be compressed such that consecutive duplicates of characters are replaced with a single character.

//    For "aaabbccdee", the compressed string will be "abcde".
//    Second compression -> The string should be compressed such that consecutive duplicates of characters are replaced with the character and followed by the number of consecutive duplicates.
//    For "aaabbccdee", the compressed string will be "a3b2c2de2".

// Input Format
// A String

// Output Format
// Two strings representing first compressed string and second compressed string respectively.

// Constraints
// 1 <= length of string <= 1000

// Sample Input
// wwwwaaadexxxxxx

// Sample Output
// wadex
// w4a3dex6

#include <iostream>
#include <string>
using namespace std;

string compression1(string str){

	string s ="";
	s += str[0];

	for(int i=1; i<str.length(); i++){

		if(str[i] != str[i-1]){
			s += str[i];
		}
	}

	return s;
}

string compression2(string str){

	string s="";
	s += str[0];
	int count = 1;

	for(int i=1; i<str.length(); i++){

		if(str[i] == str[i-1]){
			count++;
		}

		else{

			if(count > 1){
				s += to_string(count);
				count = 1;
			}

			s += str[i];
		}
	}

	if(count > 1){
		s += to_string(count);
	}

	return s;
}

int main(){

	string str;
	cin >> str;

	cout << compression1(str) << endl;
	cout << compression2(str) << endl;

	return 0;
}