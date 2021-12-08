// perfect friends
/*
1. You are given a number n (representing the number of students). Each student will have an id 
     from 0 to n - 1.
2. You are given a number k (representing the number of clubs)
3. In the next k lines, two numbers are given separated by a space. The numbers are ids of 
     students belonging to same club.
4. You have to find in how many ways can we select a pair of students such that both students are 
     from different clubs.

Input Format
Input has been managed for you

Output Format
Check the sample output

Sample Input

7
5
0 1
2 3
4 5
5 6
4 6

Sample Output
16
*/

#include <bits/stdc++.h>
using namespace std;

void findSingleCompSize(int src, vector<int> graph[], vector<bool> &vis, int &scs){

	scs++;

	vis[src] = true;

	for(int nbr : graph[src]){

		if(vis[nbr] == false){
			findSingleCompSize(nbr, graph, vis, scs);
		}
	}
}

int findPerfectFriends(vector<int> graph[], int n){

	vector<bool> vis(n, false);
	int scs; // single component size

	vector<int> comps; // graph components

	for(int i=0; i<n; i++){
		if(vis[i] == false){
			scs = 0;
			findSingleCompSize(i, graph, vis, scs);
			comps.push_back(scs);
		}
	}

	int ans=0;
	for(int i=0; i<comps.size(); i++){
		for(int j=i+1; comps.size(); j++){
			int c1s = comps[i];
			int c2s = comps[j];

			ans += (c1s * c2s);
		}
	}

	return ans;
}

int main(){

	int n, k;
	cin >> n >> k;

	vector<int> graph[n];

	for(int i=0; i<n; i++){
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << findPerfectFriends(graph, n);

	return 0;
}