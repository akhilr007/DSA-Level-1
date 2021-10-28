// node with maximum subtree sum
/*
1. You are given a partially written GenericTree class.
2. You are required to find and print the node which has the subtree with largest sum. Also print the sum of the concerned subtree separated from node's value by an '@'. Refer the question video for clarity.
3. Input is managed for you.

Input Format
Input is managed for you

Output Format
@

Constraints
None

Sample Input
20
10 20 -50 -1 60 -1 -1 30 -70 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
30@130
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
// function to calculate maximum subtree sum

int mssn = 0; // maximum subtree sum node
int mss = INT_MIN; // maximum subtree sum

int maximumSubtreeSum(Node* node){

	int sum = 0;

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		int csum = maximumSubtreeSum(child);

		sum += csum;
	}

	// add node data to the sum to get subtree sum
	sum += node->data;

	if(sum > mss){

		mssn = node->data;
		mss = sum;
	}

	return sum;
}


int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	maximumSubtreeSum(root);

	cout << mssn << "@" << mss << endl;

	return 0;
}