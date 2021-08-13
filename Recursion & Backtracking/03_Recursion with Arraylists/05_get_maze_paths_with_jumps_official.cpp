// Get Maze Path With Jumps

// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. 
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
// 4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A number n
// A number m

// Output Format
// Contents of the arraylist containing paths as shown in sample output

// Constraints
// 0 <= n <= 10
// 0 <= m <= 10

// Sample Input
// 2
// 2

// Sample Output
// [h1v1, v1h1, d1]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getMazePath(int sr, int sc, int dr, int dc){

	if(sr == dr && sc == dc){
		vector<string> bans;
		bans.push_back("");
		return bans;
	}

	else if(sr > dr || sc > dc){
		vector<string> bans;
		return bans;
	}

	vector<string> ans;
	// for horizontal jumps
	for(int k=1; sc+k <= dc; k++){

		vector<string> hpath = getMazePath(sr, sc+k, dr, dc);

		for(string path: hpath){
			ans.push_back("h" + to_string(k) + path);
		}
	}

	// for vertical jumps
	for(int k=1; sr+k <= dr; k++){

		vector<string> vpath = getMazePath(sr+k, sc, dr, dc);

		for(string path: vpath){
			ans.push_back("v" + to_string(k) + path);
		}
	}

	// for diagonal jumps
	for(int k=1; sr+k <= dr && sc+k <= dc; k++){

		vector<string> dpath = getMazePath(sr+k, sc+k, dr, dc);

		for(string path: dpath){
			ans.push_back("d" + to_string(k) + path);
		}
	}

	return ans;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> ans = getMazePath(0, 0, n-1, m-1);
	if(ans.size() == 0){
	    cout <<"[]";
	    return 0;
	}
	cout<<"[";
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i]<<", ";
    }
    cout << ans[ans.size()-1] <<"]";

    return 0;
}