// level order of generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorder function. The function is expected to visit every node in "levelorder fashion". Please check the question video for more details.
3. Input is managed for you.

Input Format
Input is managed for you

Output Format
All nodes from left to right (level by level) all separated by a space and ending in a "."

Constraints
None

Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 20 30 40 50 60 70 80 90 100 110 120 .

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

// function to find the level order of generic tree
void levelOrder(Node* node){

	queue<Node*> q;
	q.push(node);

	// algorithm -> 1. remove the node present in queue
				//  2. work 
				//  3. add the children of the remove node

	while(q.size() > 0){

		// remove
		Node* rem = q.front();
		q.pop();

		// work
		cout << rem->data <<" ";

		// add children
		for(int i=0; i<rem->children.size(); i++){

			Node* child = rem->children[i];
			q.push(child);
		}
	}

	cout <<"." <<endl;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	levelOrder(root);

	return 0;
}