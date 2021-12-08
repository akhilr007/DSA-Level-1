// is graph connected
/*
1. You are given a graph.
2. You are required to find and print if the graph is connected (there is a path from 
     every vertex to every other).

Input Format
Input has been managed for you

Output Format
true if the graph is connected, false otherwise

Sample Input
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

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

void getGraphComponents(int src, vector<Edge> graph[], vector<bool> &vis){

     vis[src] = true;

     for(Edge edge : graph[src]){

          int nbr = edge.nbr;

          if(vis[nbr] == false){
               getGraphComponents(nbr, graph, vis);
          }
     }
}

bool isGraphConnected(vector<Edge> graph[], int vtces){

     vector<bool> vis(vtces, false);

     int count = 0;
     for(int i=0; i<vtces; i++){

          if(vis[i] == false){
               count++;
               getGraphComponents(i, graph, vis);

               if(count > 1){
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


     if(isGraphConnected(graph, vtces) == 1) cout <<"true";
     else cout <<"false";
     
     return 0;
}