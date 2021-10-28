// are trees mirror in shape
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of areMirror function. The function is expected to check if the two trees passed to it are mirror images of each other in shape (data not to be checked, just the shape of tree).
Note -> Watch the question video for clarity.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
12
100 200 -1 300 500 -1 600 -1 -1 400 -1 -1

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


int main() {

	int n;
	cin >> n;

	int a1[n];
	for(int i=0; i<n; i++){
		cin >> a1[i];
	}

	int m;
	cin >> m;

	int a2[m];
	for(int i=0; i<m; i++){
		cin >> a2[i];
	}

	Node* r1 = construct(a1, n);
	Node* r2 = construct(a2, m);

	if(areMirror(r1, r2) == 1){
		cout <<"true";
	}
	else{
		cout <<"false";
	}

	return 0;
}
