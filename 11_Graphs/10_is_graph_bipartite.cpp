// is graph bipartite
/*
1. You are given a graph.
2. You are required to find and print if the graph is bipartite

Note -> A graph is called bipartite if it is possible to split it's vertices in two sets of mutually 
               exclusive and exhaustive vertices such that all edges are across sets.

Input Format
Input has been managed for you

Output Format
true if the graph is bipartite, false otherwise

Constraints
None

Sample Input
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
Sample Output
false
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

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

bool isCompBipartite(int src, vector<Edge> graph[], vector<int> &vis){

	queue<pi> q;
	q.push({src, 0}); // first -> vertices , second -> set no 0/1

	while(q.size() > 0){

		// remove 
		pi rem = q.front();
		q.pop();

		int v = rem.first;
		int sn = rem.second;

		// mark*
		if(vis[v] != -1){
			int osn = vis[v];
			int nsn = sn;

			if(osn != nsn){
				return false;
			}
			continue;
		}

		vis[v] = sn;

		// add nbr
		for(Edge edge : graph[v]){

			int nbr = edge.nbr;

			if(vis[nbr] == -1){
				int newSn = (sn == 0) ? 1 : 0;
				q.push({nbr, newSn});
			}
		}

	}

	return true;
}

bool isGraphBipartite(vector<Edge> graph[], int vtces){

	vector<int> vis(vtces, -1);

	for(int i=0; i<vtces; i++){

		if(vis[i] == -1){
			bool sca = isCompBipartite(i, graph, vis);
			if(sca == false){
				return false;
			}
		}
	}

	return true;
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

	if(isGraphBipartite(graph, vtces) == 1) cout <<"true";
	else cout <<"false";

	return 0;
}