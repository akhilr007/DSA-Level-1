// iterative dfs

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

void iterativeDFS(vector<Edge> graph[], int src, int vtces){

	vector<bool> vis(vtces, false);

	stack<pair<int, string>> st;
	st.push({src, to_string(src) });

	while(st.size() > 0){

		pair<int, string> rem = st.top();
		st.pop();

		int v = rem.first;
		string psf = rem.second;

		if(vis[v] == true){
			continue;
		}

		vis[v] = true;

		cout << v <<"@"<<psf<<endl;

		for(Edge edge: graph[v]){
			int nbr = edge.nbr;

			if(vis[nbr] == false){
				st.push({ nbr, psf + to_string(nbr) });
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

	int src;
	cin >> src;

	iterativeDFS(graph, src, vtces);
	return 0;
}