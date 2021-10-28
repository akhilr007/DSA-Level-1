// multisolver for generic tree
// find size, min, max, height of generic tree

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

static int size;
static int mini;
static int maxi;
static int height;

void multisolver(Node* node, int depth){

	size++;
	mini = min(mini, node->data);
	maxi = max(maxi, node->data);
	height = max(height, depth);

	for(Node* child : node->children){
		multisolver(child, depth+1);
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	Node* root = construct(arr, n);

	size = 0;
	mini = INT_MAX;
	maxi = INT_MIN;
	height = 0;

	multisolver(root, 0);

	cout <<"size = " << size << endl;
	cout <<"minimum = " << mini << endl;
	cout <<"maximum = " << maxi << endl;
	cout <<"height = " << height << endl;

}