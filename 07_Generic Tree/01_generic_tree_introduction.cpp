// generic tree - introduction 

// how to construct a generic tree using prefix generic tree array
// display the generic tree

#include <iostream>
#include <vector>
#include <stack>
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

	int arr[] = {10, 20, 50, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

	int n = sizeof(arr)/sizeof(arr[0]);

	Node* root = construct(arr, n);

	// display
	display(root);

	return 0;
}