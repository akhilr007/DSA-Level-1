// ceil and floor of generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to find the ceil and floor value of a given element. Use the "travel and change" strategy explained in the earlier video. The static properties - ceil and floor have been declared for you. You can declare more if you want. If the element is largest ceil will be largest integer value (32 bits), if element is smallest floor will be smallest integer value (32 bits). Watch the question video for clarity.
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
70

Sample Output
CEIL = 90
FLOOR = 60
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

static int ceiling;
static int flooring;

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

	ceiling = INT_MAX;
	flooring = INT_MIN;
	ceilAndFloor(root, data);

	cout << "CEIL = " << ceiling << endl;
	cout << "FLOOR = " << flooring << endl;

	return 0;
}