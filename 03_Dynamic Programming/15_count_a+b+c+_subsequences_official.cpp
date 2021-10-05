// count a+b+c+ subsequences
/*
1. You are given a string str.
2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
For abbc -> there are 3 subsequences. abc, abc, abbc
For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.

Input Format
A string str

Output Format
count of subsequences of the nature a+b+c+

*/

#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string str){

	int a = 0; // count of a+
	int ab = 0; // count of a+b+
	int abc = 0; // count of a+b+c+

	for(int i=0; i<str.length(); i++){

		if(str[i] == 'a'){
			// two options to get included with prev a or not 
			// and 1 option to start with itself
			a = 2*a + 1;
		}
		else if(str[i] == 'b'){
			// it also has two options to include or exclude the previous ab occurences
			// and it will add itself to the result of a to get us ab occurences
			ab = 2*ab + a;

		}
		else if(str[i] == 'c'){
			abc = 2*abc + ab;
		}
	}

	return abc;
}

int main(){

	string str;
	cin >> str;

	cout << countSubsequences(str);
	return 0;
}