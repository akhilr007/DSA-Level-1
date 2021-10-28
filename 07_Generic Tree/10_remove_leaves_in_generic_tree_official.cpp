// remove leaves in generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of removeLeaves function. The function is expected to remove all leaves from the tree. For more details, check out the question video.
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
10 -> 20, 30, 40, .
20 -> .
30 -> 80, .
80 -> .
40 -> .
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

void removeLeaves(Node* node){

	// first remove the child nodes that have size of their children to be zero.
	for(int i=node->children.size()-1; i>=0; i--){

		Node* child = node->children[i];

		if(child->children.size() == 0){

			// erase the node
			node->children.erase(node->children.begin() + i);
		}
	}

	// go to the child node
	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		removeLeaves(child);
	}
}

void display(Node* node){

	cout <<node->data<<" -> ";
	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		cout << child->data <<", ";
	}

	cout <<"." <<endl;

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

	removeLeaves(root);

	display(root);

	return 0;
}