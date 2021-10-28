// node to root path in generic tree
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of nodeToRootPath function. The function is expected to return in form of linked list the path from element to root, if the element with data is found.
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
120

Sample Output
[120, 80, 30, 10]
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

vector<int> nodeToRootPath(Node* node, int data){

	if(node->data == data){

		vector<int> list;
		list.push_back(data);
		return list;
	}	

	for(int i=0; i<node->children.size(); i++){

		Node* child = node->children[i];

		vector<int> n2cp = nodeToRootPath(child, data);

		if(n2cp.size() > 0){

			n2cp.push_back(node->data); // converting n2cp(node to child path) into n2rp (node to root path).
			return n2cp;
		}
	}

	return vector<int> ();
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

	vector<int> res = nodeToRootPath(arr, data);

	if(res.size() == 0){
	    cout <<"[]";
	}
    else{
	    cout <<"[";
    	for(int i=0; i<res.size()-1; i++){
    
    		cout<<res[i]<<", ";
    	}
    	cout << res[res.size()-1]<<"]";
    }


	return 0;
}

