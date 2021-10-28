// levelorder linewise zig zag
/*
1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorderLineWiseZZ function. The function is expected to visit every node in "levelorder fashion" but in a zig-zag manner i.e. 1st level should be visited from left to right, 2nd level should be visited from right to left and so on. All nodes on same level should be separated by a space. Different levels should be on separate lines. Please check the question video for more details.
3. Input is managed for you. 
                               
Input Format
Input is managed for you

Output Format
All nodes on the same level should be separated by a space.
1st level should be visited left to right, 2nd from right to left and so on alternately.
All levels on separate lines starting from top to bottom.

Constraints
None

Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 
40 30 20 
50 60 70 80 90 100 
120 110
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

void levelOrderZigzag(Node* node){

	queue<Node*> q;
	int level = 0;
	q.push(node);

	while(q.size() > 0){

		int count = q.size();
		vector<int> list;

		for(int k=0; k<count; k++){

			Node* rem = q.front();
			q.pop();

			list.push_back(rem->data);

			for(int i=0; i<rem->children.size(); i++){

				Node* child = rem->children[i];
				q.push(child);
			}
		}

		if(level % 2 == 0){

			for(int i=0; i<list.size(); i++){

				cout << list[i] <<" ";
			}
			cout << endl;
		}
		else{

			for(int i=list.size()-1; i>=0; i--){
				cout <<list[i] <<" ";
			}
			cout <<endl;
		}

		level++;
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

	levelOrderZigzag(root);

	return 0;
}