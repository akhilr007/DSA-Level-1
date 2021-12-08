// number of islands
/*
1. You are given a 2d array where 0's represent land and 1's represent water. 
     Assume every cell is linked to it's north, east, west and south cell.
2. You are required to find and count the number of islands.

Input Format
Input has been managed for you

Output Format
Number of islands

Sample Input
8
8
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 0 0 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0

Sample Output
3
*/

#include <bits/stdc++.h>
using namespace std;

void travel(int i, int j, vector<vector<int>> &graph, vector<vector<bool>> &vis){

	if(i < 0 || j < 0 || i >= graph.size() || j >= graph[0].size() || graph[i][j] == 1 || vis[i][j] == true){
		return;
	}

	vis[i][j] = true;

	// top
	travel(i-1, j, graph, vis);
	// left
	travel(i, j-1, graph, vis);
	// down
	travel(i+1, j, graph, vis);
	// right
	travel(i, j+1, graph, vis);
}

int numberOfIslands(vector<vector<int>> &graph){

	int n = graph.size();
	int m = graph[0].size();

	vector<vector<bool>> vis(n, vector<bool> (m, false));

	int count=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(graph[i][j] == 0 && vis[i][j] == false){
				travel(i, j, graph, vis);
				count++;
			}
		}
	}

	return count;
}