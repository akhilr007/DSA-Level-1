// count encodings
/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z

3. You are required to calculate and print the count of encodings for the string str.

     For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic 
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
     print 0.

Input Format
A string str

Output Format
count of encodings

Constraints
0 < str.length <= 10

Sample Input
123

Sample Output
3
*/

#include <bits/stdc++.h>
using namespace std;

int countDecoding(string s, int n){

	// base case -> if the length of string is 0 or 1 then only 1 encoding is possible
	if(n == 0 || n == 1){
		return 1;
	}

	int count = 0;
	// if the last char of string is greater than 0 then the encoding can be added to string
	if(s[n-1] > '0'){
		count = countDecoding(s, n-1);
	}

	// if the last two char of string is less than 26 then it can also be added to string
	if(s[n-2] == '1' || s[n-2] == '2' && s[n-1] < '7'){
		count += countDecoding(s, n-2);
	}

	return count;
}

int countEncoding(string s, int n){

	// if string length is zero or starting of string is zero
	// then no possible encodings are possible
	if(n == 0 || (n == 1 && s[0] == '0')){
		return 0;
	}

	return countDecoding(s, n);
}

int countEncoding_tab(string s, int n){

	int dp[n+1];

	// dp[i] -> count of encoded string from [0, i]

	if(s[0] == '0'){
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;

	for(int i=2; i<=n; i++){
        
        dp[i] = 0;
        
		if(s[i-1] > '0'){
			dp[i] = dp[i-1];
		}

		if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <'7')){
			dp[i] += dp[i-2];
		}
	}

	return dp[n];
}

int main(){

	string s;
	cin >> s;

	// recursion
	cout << countEncoding(s, s.length());

	// tabulation
	cout << countEncoding_tab(s, s.length());

	return 0;
}