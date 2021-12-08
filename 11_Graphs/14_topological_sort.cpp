// topological sort - order of compilation
/*
1. You are given a directed acyclic graph. The vertices represent tasks and edges represent 
    dependencies between tasks.
2. You are required to find and print the order in which tasks could be done. The task that should be 
    done at last should be printed first and the task which should be done first should be printed last. 
    This is called topological sort. Check out the question video for details.

Topological sort -> A permutation of vertices for a directed acyclic graph is called topological sort if 
                                    for all directed edges uv, u appears before v in the graph

Note -> For output, check the sample output and question video.

Input Format
Input has been managed for you

Output Format
Check the sample output

Sample Input
7
7
0 1
1 2
2 3
0 3
4 5
5 6
4 6

Sample Output
4
5
6
0
1
2
3
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src;
        int nbr;
        
        Edge(int src, int nbr){
            this->src = src;
            this->nbr = nbr;
        }
};

void dfs(int src, vector<Edge> graph[], vector<bool> &vis, stack<int> &st){

	vis[src] = true;

	for(Edge edge : graph[src]){
        
        int nbr = edge.nbr;
        
		if(vis[nbr] == false){
			dfs(nbr, graph, vis, st);
		}
	}

	st.push(src);
}

void topologicalSort(vector<Edge> graph[], int vtces){

	vector<bool> vis(vtces, false);
	stack<int> st;

	for(int i=0; i<vtces; i++){

		if(vis[i] == false){
			dfs(i, graph, vis, st);
		}
	}

	while(st.size() > 0){
		int val = st.top(); st.pop();
		cout << val << endl;
	}
}

int main(){
	int vtces;
	cin >> vtces;

	vector<Edge> graph[vtces];

	int edges;
	cin >> edges;

	for(int i=0; i<edges; i++){
		int u, v;
		cin >> u >> v;

		graph[u].push_back(Edge(u, v));
	}

	topologicalSort(graph, vtces);
	return 0;
}
