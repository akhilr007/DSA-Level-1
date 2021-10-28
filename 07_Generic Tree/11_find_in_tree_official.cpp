// find in generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of find function. The function is expected to find the given data in the tree, if found it should return true or return false.
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
120

Sample Output
true
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

// function to find the data in generic tree
bool findInGenericTree(Node* node, int data){

	if(node->data == data){
		return true;
	}

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		if(findInGenericTree(child, data) == true){
			return true;
		}
	}

	return false;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int data;
	cin >> data;

	Node* root = construct(arr, n);

	if(findInGenericTree(root, data) == 1){
		cout <<"true";
	}
	else{
		cout <<"false";
	}

	return 0;
}

