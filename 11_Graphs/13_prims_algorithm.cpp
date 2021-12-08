// prims algorithm -> minimum wire required to connect all pieces
/*
1. You are given a graph and a source vertex. The vertices represent computers and the edges 
     represent length of LAN wire required to connect them.
2. You are required to find the minimum length of wire required to connect all PCs over a network. 
     Print the output in terms of which all PCs need to be connected, and the length of wire between 
     them.

Note -> For output, check the sample output and question video.

Input Format
Input has been managed for you

Output Format
Check the sample output

Sample Input
7
8
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8

Sample Output
[1-0@10]
[2-1@10]
[3-2@10]
[4-3@2]
[5-4@3]
[6-5@3]
*/

#include <bits/stdc++.h>
#define pii pair<int, pair<int, int>>
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

void prims(vector<Edge> graph[], int vtces){

	vector<bool> vis(vtces, false);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, {0, -1} });

	while(pq.size() > 0){

		pii rem = pq.top();
		pq.pop();

		int wt = rem.first;
		int v = rem.second.first;
		int aqv = rem.second.second;

		if(vis[v] == true){
			continue;
		}

		vis[v] = true;
        
        if(aqv != -1){
		    cout <<"["<<v<<"-"<<aqv<<"@"<<wt<<"]"<<endl;
        }

		for(Edge edge : graph[v]){
			int nbr = edge.nbr;
			int weight = edge.wt;

			if(vis[nbr] == false){
				pq.push({weight, {nbr, v} });
			}
		}
	}
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

	prims(graph, vtces);
	return 0;
}
