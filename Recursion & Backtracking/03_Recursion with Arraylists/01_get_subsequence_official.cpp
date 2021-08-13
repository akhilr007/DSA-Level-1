// Get Subsequence

// 1. You are given a string str.
// 2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
// Use sample input and output to take idea about subsequences.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
// Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A string str'

// Output Format
// Contents of the arraylist containing subsequences as shown in sample output

// Constraints
// 0 <= str.length <= 20

// Sample Input
// abc

// Sample Output
// [, c, b, bc, a, ac, ab, abc]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getSS(string str){

	if(str.length() == 0){
		vector<string> bans;
		bans.push_back("");
		return bans;
	}

	char ch = str[0];
	string ros = str.substr(1);

	vector<string> rans = getSS(ros);
	vector<string> myAns;

	// ch with no choice
	for(int i=0; i<rans.size(); i++){
		myAns.push_back(rans[i]);
	}

	// ch with choice
	for(int i=0; i<rans.size(); i++){
		myAns.push_back(ch + rans[i]);
	}

	return myAns;
}

int main() {

	string str;
	cin >> str;

	vector<string> ans = getSS(str);

	cout<<"[";
	for(int i=0; i<ans.size()-1; i++){
		cout << ans[i]<<", ";
	}
	cout << ans[ans.size()-1] <<"]";

	return 0;
}