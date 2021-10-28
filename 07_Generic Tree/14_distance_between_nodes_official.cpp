// distance between two nodes
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of distanceBetweenNodes function. The function is expected to return the distance (in terms of number of edges) between two nodes in a generic tree.
Please watch the question video to understand what lca is.
3. Input and Output is managed for you. 
                               
Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
100
110

Sample Output
5
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;

	Node(int x){
		data = x;
	}
};

Node* construct(int arr[], int n){

	stack<Node*> st;
	Node* root = NULL;

	for(int i=0; i<n; i++){

		if(arr[i] == -1){
			st.pop();
		}
		else{

			Node* nn = new Node(arr[i]);

			if(st.size() == 0){
				root = nn;
			}
			else{
				Node* par = st.top();
				par->children.push_back(nn);
			}
			st.push(nn);
		}
	}

	return root;
}

vector<int> nodeToRootPath(Node* node, int data){

	if(node->data == data){

		vector<int> list;
		list.push_back(data);
		return list;
	}

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		vector<int> n2cp = nodeToRootPath(child, data);

		if(n2cp.size() > 0){

			n2cp.push_back(node->data);
			return n2cp;
		}
	}

	return {};
}

int distanceBetweenNodes(Node* node, int d1, int d2){

	vector<int> p1 = nodeToRootPath(node, d1);
	vector<int> p2 = nodeToRootPath(node, d2);

	int i = p1.size()-1;
	int j = p2.size()-1;

	while(i >=0 && j >= 0 && p1[i] == p2[j]){
		i--;
		j--;
	}

	i++;
	j++;
	return i + j;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int d1, d2;
	cin >> d1 >> d2;

	Node* root = construct(arr, n);

	cout << distanceBetweenNodes(root, d1, d2);

	return 0;
}

