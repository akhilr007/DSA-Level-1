// spread of infection
/*
1. You are given a graph, representing people and their connectivity.
2. You are also given a src person (who got infected) and time t.
3. You are required to find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time.

Input Format
Input has been managed for you

Output Format
count of people infected by time t

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
6
3

Sample Output
4
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

int spreadInfection(vector<Edge> graph[], int src, int t, int vtces){

	vector<bool> vis(vtces, false);
	queue<int> q;
	q.push(src);

	int isf = 0; // infected so far

	while(q.size() > 0){

		int count = q.size();
		if(t < 0) break;

		for(int i=1; i<=count && t>0; i++){

			// rem
			int rem = q.front();
			q.pop();

			//mark*
			if(vis[rem] == true){
				continue;
			}
			vis[rem] = true;

			// work
			isf++;

			// add nbr*
			for(Edge edge : graph[rem]){
				int nbr = edge.nbr;

				if(vis[nbr] == false){
					q.push(nbr);
				}
			}
		}
		t--;
	}

	return isf;
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

	int src, t;
	cin >> src >> t;

	cout << spreadInfection(graph, src, t, vtces);

	return 0;
}