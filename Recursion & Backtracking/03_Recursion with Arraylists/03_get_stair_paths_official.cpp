// Get Stair Paths

// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
// 3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
// Use sample input and output to take idea about output.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A number n

// Output Format
// Contents of the arraylist containing paths as shown in sample output

// Constraints
// 0 <= n <= 10

// Sample Input
// 3

// Sample Output
// [111, 12, 21, 3]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getStairPaths(int n){

	if(n == 0){
		vector<string> bans;
		bans.add("");
		return bans;
	}
	if(n < 0){
		vector<string> bans;
		return bans;
	}

	vector<string> paths1 = getStairPaths(n-1);
	vector<string> paths2 = getStairPaths(n-2);
	vector<string> paths3 = getStairPaths(n-3);

	vector<string> paths;

	for(string path: paths1){
		paths.push_back('1' + path);
	}

	for(string path: paths2){
		paths.push_back('2' + path);
	}

	for(string path: paths3){
		paths.push_back('3' + path);
	}

	return path;
}

int main() {

	int n;
	cin >> n;

	vector<string> ans = getStairPaths(n);
	cout<<"[";
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i]<<", ";
    }
    cout << ans[ans.size()-1] <<"]";

    return 0;
}