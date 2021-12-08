// hamiltonian path and cycle
/*
1. You are given a graph and a src vertex.
2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
Note -> Print in lexicographically increasing order.

Input Format
Input has been managed for you

Output Format
Check sample output

Sample Input
7
9
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
2 5 10

0

Sample Output
0123456.
0123465.
0125643*
0346521*

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

void hamiltonian(vector<Edge> graph[], int src, int osrc, int vtces, vector<bool> &vis, string psf){

	if(psf.length() == vtces){

		bool isHC = false;

		for(Edge edge : graph[osrc]){
			int nbr = edge.nbr;

			if(nbr == src){
				isHC = true;
			}
		}

		cout << psf ;

		if(isHC == true){
			cout <<"*"<<endl;
		}
		else{
			cout <<"."<<endl;
		}

		return;
	}

	vis[src] = true;

	for(Edge edge : graph[src]){

		int nbr = edge.nbr;

		if(vis[nbr] == false){
			hamiltonian(graph, nbr, osrc, vtces, vis, psf + to_string(nbr));
		}
	}

	vis[src] = false;
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

	int src;
	cin >> src;

	vector<bool> vis(vtces, false);
	hamiltonian(graph, src, src, vtces, vis, ""+to_string(src));

	return 0;
}