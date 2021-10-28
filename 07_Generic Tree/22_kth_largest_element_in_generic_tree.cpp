// kth largest element in generic tree
/*
1. You are given a partially written GenericTree class.
2. You are given a number k. You are required to find and print the kth largest value in the tree.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
24
10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1
8

Sample Output
10
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

int ceiling = INT_MAX;
int flooring = INT_MIN;

// function to calculate ceil and floor
void ceilAndFloor(Node* node, int data){

	if(node->data > data){
		if(node->data < ceiling){
			ceiling = node->data;
		}
	}
	else if(node->data < data){
		if(node->data > flooring){
			flooring = node->data;
		}
	}

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		ceilAndFloor(child, data);
	}
}

// function to find kth largest element in generic tree
int kthLargestElement(Node* node, int k){

	int key = INT_MAX;

	for(int i=0; i<k; i++){
		flooring = INT_MIN;
		ceilAndFloor(node, key);
		key = flooring;
	}

	return key;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;

	Node* root = construct(arr, n);
	
	cout << kthLargestElement(root, k);

	return 0;
}