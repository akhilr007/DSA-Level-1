// diameter of generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to find and print the diameter of tree. THe diameter is defined as maximum number of edges between any two nodes in the tree. Check the question video for clarity.
3. Input is managed for you.

Input Format
Input is managed for you

Output Format
diameter

Constraints
None

Sample Input
20
10 20 -50 -1 60 -1 -1 30 -70 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
4
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

int dia = 0;

int diameterOfGenericTree(Node* node){

	int bcht = -1; // best child height
	int sbcht = -1; // second best child height

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		int cht = diameterOfGenericTree(child);

		if(cht > bcht){
			sbcht = bcht;
			bcht = cht;
		}
		else if(cht > sbcht){
			sbcht = cht;
		}
	}

	int dist = bcht + sbcht + 2;

	if(dist > dia){
		dia = dist;
	}

	return bcht + 1;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	diameterOfGenericTree(root);

	cout << dia << endl;

	return 0;
}