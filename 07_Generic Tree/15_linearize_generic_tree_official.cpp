// linearize a generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of linearize function. The function is expected to create a linear tree i.e. every node will have a single child only. For details check the question video.
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

Sample Output
10 -> 20, .
20 -> 50, .
50 -> 60, .
60 -> 30, .
30 -> 70, .
70 -> 80, .
80 -> 110, .
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

// function to find the tail node of second last child
Node* getTail(Node* node){

	while(node->children.size() == 1){

		node = node->children[0];
	}

	return node;
}

// function to linearize the generic tree
void linearize(Node* node){

	for(int i=0; i<node->children.size(); i++){
		Node* child = node->children[i];
		linearize(child);
	}

	// self work for node 
	while(node->children.size() > 1){

		int s = node->children.size();

		// take hold of last child and second last child
		Node* lc = node->children[s-1];
		Node* slc = node->children[s-2];

		// remove the lc 
		node->children.erase(node->children.begin()+s-1);

		// find tail of the second last child
		Node* tail = getTail(slc);

		// add lc to the tail of slc
		tail->children.push_back(lc);
	}
}

void display(Node* node){

	cout << node->data <<" -> ";
	for(int i=0; i<node->children.size(); i++){
		Node* child = node->children[i];
		cout << child->data <<", ";
	}

	cout <<"."<<endl;

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		display(child);
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	linearize(root);

	display(root);

	return 0;
}

