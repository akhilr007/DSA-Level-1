//target sum pair in bst
/*
1. You are given a partially written BST class.
2. You are given a value. You are required to print all pair of nodes which add up to the given value. Make sure all pairs print the smaller value first and avoid duplicacies. Make sure to print the pairs in increasing order. Use the question video to gain clarity.
3. Input and Output is managed for you. 

Input Format
Input is managed for you

Output Format
"smaller node" "larger node"
.. all pairs that add to target on separate lines
*/

// first solution -> 0(nlogn)

bool find(Node* root, int data){

	if(root == NULL) return false;

	if(root->data > data){
		return find(root->left, data);
	}
	else if(root->data < data){
		return find(root->right, data);
	}
	else{
		return true;
	}
}


void targetSumPair(Node* root, Node* node, int tar){

	if(node == NULL) return;

	targetSumPair(root, node->left, tar);

	int comp = tar - node->data;

	if(node->data < comp){

		if(find(root, comp) == true){

			cout << node->data <<" "<<comp<<endl;
		}
	}

	targetSumPair(root, node->right, tar);
}

// efficient solution -> 0(n)->tc O(h)->sc

Node* getNextFromNormalInorder(stack<pair<Node*, int>> &st){

	while(st.size() > 0){

		int state = st.top().second;

		if(state == 0){
			// pre
			st.top().second++;

			if(st.top().first->left != NULL){
				st.push({st.top().first->left,0});
			}
		}
		else if(state == 1){
			// in
			st.top().second++;
			Node* myNode = st.top().first;

			if(st.top().first->right != NULL){
				st.push({st.top().first->right, 0});
			}

			return myNode;
		}
		else{
			// post
			st.pop();
		}
	}
}

Node* getNextFromReverseInorder(stack<pair<Node*, int>> &st){

	while(st.size() > 0){

		int state = st.top().second;

		if(state == 0){
			// pre
			st.top().second++;

			if(st.top().first->right != NULL){
				st.push({st.top().first->right,0});
			}
		}
		else if(state == 1){
			// in
			st.top().second++;
			Node* myNode = st.top().first;

			if(st.top().first->left != NULL){
				st.push({st.top().first->left, 0});
			}

			return myNode;
		}
		else{
			// post
			st.pop();
		}
	}
}

void targetSumPair(Node* node, int tar){

	stack<pair<Node*, int>> ls; // stores normal inorder
	stack<pair<Node*, int>> rs; // stores reverse inorder;

	ls.push({node, 0});
	rs.push({node, 0});

	Node* left = getNextFromNormalInorder(ls);
	Node* right = getNextFromReverseInorder(rs);

	if(left->data + right->data < tar){
		left = getNextFromNormalInorder(ls);
	}
	else if(left->data + right->data > tar){
		right = getNextFromReverseInorder(rs);
	}
	else{
		cout << left->data <<" "<<right->data<<endl;
		left = getNextFromNormalInorder(ls);
		right = getNextFromReverseInorder(rs);
	}

}