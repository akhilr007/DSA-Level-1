// breadth first traversal
/*
1. You are given a graph, and a src vertex.
2. You are required to do a breadth first traversal and print which vertex is reached via which path, 
     starting from the src.

Note -> for output, check the sample output and question video.

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
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
2

Sample Output
2@2
1@21
3@23
0@210
4@234
5@2345
6@2346
*/

#include <bits/stdc++.h>
#define pi pair<int, string>
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

void bfs(vector<Edge> graph[], int src, int vtces){

	vector<bool> vis(vtces, false);

	queue<pi> q;
	string str = to_string(src);
	q.push({src, str});

	while(q.size() > 0){
	    
	    int count = q.size();
	    
	    for(int i=0; i<count; i++){
	   
	        // remove
    		pi rem = q.front();
    		q.pop();
    
    		//mark*
    		if(vis[rem.first] == true){
    			continue;
    		}
    		vis[rem.first] = true;
    
    		// work
    		cout << rem.first << "@" << rem.second;
    
    		// add nbr*
    		for(Edge edge : graph[rem.first]){
    			int nbr = edge.nbr;
    
    			if(vis[nbr] == false){
    			    string s = rem.second + to_string(nbr);
    				q.push({nbr, s });
    			}
    		}
    		cout << endl;
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

	int src;
	cin >> src;

	bfs(graph, src, vtces);

	return 0;
}