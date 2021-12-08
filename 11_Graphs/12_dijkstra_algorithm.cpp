// shortest path in weights
/*
1. You are given a graph and a source vertex. The vertices represent cities and the edges represent 
    distance in kms.
2. You are required to find the shortest path to each city (in terms of kms) from the source city along 
    with the total distance on path from source to destinations.

Note -> For output, check the sample output and question video.

Input Format
Input has been managed for you

Output Format
Check the sample output

Sample Input
7
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0

Sample Output
0 via 0 @ 0
1 via 01 @ 10
2 via 012 @ 20
5 via 0125 @ 25
4 via 01254 @ 28
6 via 01256 @ 28
3 via 012543 @ 30
*/

#include <bits/stdc++.h>
#define pis pair<int, pair<int, string>>
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

void dijkstra(vector<Edge> graph[], int src, int n){

	vector<bool> vis(n, false);
	vector<int> dis(n, 0);
	
	priority_queue<pis, vector<pis>, greater<pis>> pq;
	
	string str = to_string(src);
	pq.push({ 0, {src, str} });

	while(pq.size() > 0){

		pis rem = pq.top();
		pq.pop();

		int wsf = rem.first;
		int v = rem.second.first;
		string psf = rem.second.second;

		if(vis[v] == true){
			continue;
		}
		
		vis[v] = true;
		
		cout << v <<" via " << psf <<" @ "<< wsf<<endl;
		dis[v] = wsf;
		
		for(Edge edge : graph[v]){
			int nbr = edge.nbr;
			int wt = edge.wt;
			
			if(vis[nbr] == false){
				string s = psf + to_string(nbr);
				int total_weight = wsf + wt;
				
				pq.push({ total_weight, {nbr, s} });
			}
		}
	}
	
	for(int i=0; i<n; i++){
	    cout << dis[i] <<" ";
	}

}

int main(){
    
    int n;
	cin >> n;

	vector<Edge> graph[n];
	int m;
	cin >> m;

	for(int i=0; i<m; i++){
		int u, v, wt;
		cin >> u >> v >> wt;

		graph[u].push_back(Edge(u, v, wt));
		graph[v].push_back(Edge(v, u, wt));
	}

	int src;
	cin >> src;

	dijkstra(graph, src, n);
	return 0;
}
