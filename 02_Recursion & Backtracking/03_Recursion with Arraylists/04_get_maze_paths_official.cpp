// Get Maze Paths

// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
// 3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
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
// 3
// 3

// Sample Output
// [hhvv, hvhv, hvvh, vhhv, vhvh, vvhh]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// sr-source row
// sc-source col
// dr-destination row
// dc-destination col

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

	vector<string> hpath = getMazePath(sr, sc+1, dr, dc);
	vector<string> vpath = getMazePath(sr+1, sc, dr, dc);

	vector<string> ans;

	for(string path: hpath){
		ans.push_back('h' + path);
	}

	for(string path: vpath){
		ans.push_back('v' + path);
	}

	return ans;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> ans = getMazePath(0, 0, n-1, m-1);
	cout<<"[";
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i]<<", ";
    }
    cout << ans[ans.size()-1] <<"]";

    return 0;
}