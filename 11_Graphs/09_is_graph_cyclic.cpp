// is graph cyclic
/*
1. You are given a graph.
2. You are required to find and print if the graph is cyclic.

Input Format
Input has been managed for you

Output Format
true if the graph is cyclic, false otherwise

Constraints
None

Sample Input
7
6
0 1 10
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10

Sample Output
false
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

bool isCompCylic(int src, vector<Edge> graph[], vector<bool> &vis){

	queue<int> q;
	q.push(src);

	while(q.size() > 0){

		// remove
		int rem = q.front();
		q.pop();

		// mark*
		if(vis[rem] == true){
			return true;
		}

		vis[rem] = true;

		// add nbr

		for(Edge edge: graph[rem]){

			int nbr = edge.nbr;

			if(vis[nbr] == false){
				q.push(nbr);
			}
		}
	}

	return false;
}

bool isGraphCyclic(vector<Edge> graph[], int vtces){

	vector<bool> vis(vtces, false);

	for(int i=0; i<vtces; i++){

		if(vis[i] == false){
			bool sca = isCompCylic(i, graph, vis);

			if(sca == true){
				return true;
			}
		}
	}

	return false;
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

	if(isGraphCyclic(graph, vtces) == 1) cout <<"true";
	else cout <<"false";

	return 0;
}