// mirror a generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of mirror function. The function is expected to create a mirror image of the tree. For more details, check out the question video.
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
20 -> 50, 60, .
50 -> .
60 -> .
30 -> 70, 80, 90, .
70 -> .
80 -> 110, 120, .
110 -> .
120 -> .
90 -> .
40 -> 100, .
100 -> .
10 -> 40, 30, 20, .
40 -> 100, .
100 -> .
30 -> 90, 80, 70, .
90 -> .
80 -> 120, 110, .
120 -> .
110 -> .
70 -> .
20 -> 60, 50, .
60 -> .
50 -> .

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

// function to make the mirror tree
void mirrorTree(Node* node){

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		mirrorTree(child);
	}

	// reverse the node's children arraylist
	int l = 0;
	int r = node->children.size()-1;

	while(l < r){

		Node* ln = node->children[l];
		Node* rn = node->children[r];

		node->children[l] = rn;
		node->children[r] = ln;

		l++;
		r--;
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

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	display(root);
	mirrorTree(root);
	display(root);

	return 0;
}
