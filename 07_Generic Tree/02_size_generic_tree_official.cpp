// size of generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of size function. The function is expected to count the number of nodes in the tree and return it.
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
6
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

// function to find the tree size --> 
int treeSize(Node* node){

	int size = 0;

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		// calculate the size of child family
		int cfs = treeSize(child);

		// add the child size to the head size
		size += cfs;
	}

	return size+1;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	// construct generic tree from given prefix order of generic tree
	Node* root = construct(arr, n);

	// calculate the size of generic tree
	cout << treeSize(root);

	return 0;
}