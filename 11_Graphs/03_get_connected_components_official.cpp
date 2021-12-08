// get connected components of a graph
/*
1. You are given a graph.
2. You are required to find and print all connected components of the graph.

Input Format
Input has been managed for you

Output Format
Check the sample output

Sample Input
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

Sample Output
[[0, 1], [2, 3], [4, 5, 6]]
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src;
	int nbr;
	int wt;

	Edge(int src, int nbr, int wt){
		this->src = src;
		this->nbr = nbr;
		this->wt = wt;
	}
};

// function to get connected components

void getSingleConnectedComps(int src, vector<Edge> graph[], vector<int> &scc, vector<int> &vis){

	// add
	scc.push_back(src);

	// mark
	vis[src] = true;

	// add nbr
	for(Edge edge : graph[src]){

		int nbr = edge.nbr;

		if(vis[nbr] == false){
			getSingleConnectedComps(nbr, graph, scc, vis);
		}
	}
}

vector<vector<int>> getConnectedComponents(vector<Edge> graph[], int vtces){

	vector<bool> vis(vtces, false);

	vector<vector<int>> comps;
	for(int i=0; i<vtces; i++){

		if(vis[i] == false){
			vector<int> scc; // get single component
			getSingleConnectedComps(i, graph, scc, vis);
			comps.push_back(scc);
		}
	}

	return comps;
}

int main(){

	int vtces;
	cin >> vtces;

	vector<Edge> graph[vtces];

	int edges;
	cin >> edges;

	for(int i=0; i<edges; i++){
		int u, v, wt;
		cin >> u >> v >> wt;

		graph[u].push_back(Edge(u, v, wt));
		graph[v].push_back(Edge(v, u, wt));
	}

	vector<vector<int>> comps = getConnectedComponents(graph, vtces);

	cout << "[";
  	for (int i = 0 ; i < comps.size() ; i++) {
    	cout << "[";
    	for (int j = 0 ; j < comps[i].size() ; j++) {
      	if (j != comps[i].size() - 1)
        	cout << comps[i][j] << ", ";
      	else
        	cout << comps[i][j];
	}
    cout << "]";
    if (i != comps.size() - 1)cout << ", ";
  }
  cout << "]";

  return 0;
}