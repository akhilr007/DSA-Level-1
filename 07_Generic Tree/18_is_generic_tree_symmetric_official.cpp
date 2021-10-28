// is generic tree symmetrical
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of IsSymmetric function. The function is expected to check if the tree is symmetric, if so return true otherwise return false. For knowing symmetricity think of face and hand. Face is symmetric while palm is not. Also, we are check only smmetricity of shape and not content. Check the question video for clarity.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
20
10 20 50 -1 60 -1 -1 30 70 -1 80 -1 90 -1 -1 40 100 -1 110 -1 -1 -1

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

// function to find are trees mirror in shape
bool areMirror(Node* n1, Node* n2){

	if(n1->children.size() != n2->children.size()){
		return false;
	}

	for(int i=0; i<n1->children.size(); i++){

		Node* c1 = n1->children[i];
		Node* c2 = n2->children[n2->children.size()-i-1];

		if(areMirror(c1, c2) == false){
			return false;
		}
	}

	return true;
}

bool isSymmetric(Node* node){

	return areMirror(node, node);
}


int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	if(isSymmetric(root) == 1){
		cout <<"true";
	}
	else{
		cout <<"false";
	}

	return 0;
}
