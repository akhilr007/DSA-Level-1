// lowest common ancestor(generic tree)
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of lca function. The function is expected to return the lowest common ancestor of two data values that are passed to it. 
Please watch the question video to understand what lca is.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you
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

int lowestCommonAncestor(Node* node, int d1, int d2){

	// find node to root path for d1 and d2
	vector<int> p1 = nodeToRootPath(node, d1);
	vector<int> p2 = nodeToRootPath(node, d2);

	int i = p1.size()-1;
	int j = p2.size()-1;

	// starting from behind the two arrays p1 and p2
	// if the data is same then decrement both i and j 
	// if at any time it data is not same in both arrays break from loop and return the last matching data;
	while(i>=0 && j>=0 && p1[i] == p2[j]){
		i--;
		j--;
	}

	return p1[i+1];
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

	cout << lowestCommonAncestor(root, d1, d2);

	return 0;
}

