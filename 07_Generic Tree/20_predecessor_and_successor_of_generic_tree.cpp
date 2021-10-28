//Predecessor And Successor Of An Element
/*
1. You are given a partially written GenericTree class.
2. You are required to find the preorder predecessor and successor of a given element. Use the "travel and change" strategy explained in the earlier video. The static properties have been declared for you. You can declare more if you want.
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
-120

Sample Output
Predecessor = 110
Successor = 90
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

static Node* predecessor;
static Node* successor;
static int state;

void predecessorAndSuccessor(Node* node, int data){

	if(state == 0){

		if(node->data == data){
			state = 1;
		}
		else{
			predecessor = node;
		}
	}
	else if(state == 1){

		successor = node;
		state = 2;
	}

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];
		predecessorAndSuccessor(child, data);
	}
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

	predecessor = NULL;
	successor = NULL;
	state = 0;

	predecessorAndSuccessor(root, data);

	if(predecessor == NULL){
      cout << "Predecessor = Not found"<<endl;
    } else {
      cout << "Predecessor = " << predecessor->data <<endl;
    }

    if(successor == NULL){
      cout << "Successor = Not found"<<endl;
    } else {
      cout << "Successor = " << successor->data << endl;
    }
	
	return 0;
}