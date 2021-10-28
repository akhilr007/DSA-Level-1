// height of a generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of height function. 
The function is expected to find the height of tree. 
Depth of a node is defined as the number of edges it is away from the root (depth of root is 0). 
Height of a tree is defined as depth of deepest node.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1

Sample Output
2
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

int height(Node* node){

	// child best height
	int cbht = -1;// height in terms of edges

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		int ht = height(child);

		if(ht > cbht){
			cbht = ht;
		}
	}

	return cbht + 1;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	cout << height(root);

	return 0;
}