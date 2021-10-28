// iterative preorder and postorder
/*
1. You are given a partially written GenericTree class.
2. You are require to complete the body of function IterativePreandPostOrder. The function does not use recursion and prints preorder and postorder of the tree. Both orders are printed in separate lines (preorder first, followed by post order in next line). Elements in an order are separated by space.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Elements in preorder separated by a space
Elements in postorder separated by a space

Constraints
None

Sample Input
24
10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
10 20 -50 60 30 70 -80 110 -120 90 40 -100 
-50 60 20 70 110 -120 -80 90 30 -100 40 10 
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

void iterativePreAndPostOrder(Node* root){
    
    stack<pair<Node*, int>> st;
    st.push({root, -1});
    
    string pre = "";
    string post = "";
    
    while(st.size() > 0){
        
        Node* node = st.top().first;
        int state = st.top().second;
        
        if(state == -1){
            
            pre += to_string(node->data) + " ";
            st.top().second++;
        }
        
        else if(state < node->children.size()){
            
            Node* child = node->children[state];
            st.top().second++;
            st.push({child, -1});
        }
        
        else if(state == node->children.size()){
            
            post += to_string(node->data) + " ";
            st.pop();
        }
    }
    
    cout << pre << endl;
    cout << post << endl;
}


int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	iterativePreAndPostOrder(root);
	return 0;
}