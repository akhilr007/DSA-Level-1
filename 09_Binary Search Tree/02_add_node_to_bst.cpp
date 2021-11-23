// add node to bst
/*
1. You are given a partially written BST class.
2. You are required to complete the body of add function. "add" function is expected to add a new node with given data to the tree and return the new root.
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you
*/

// function to add node in bst
Node* add(Node* node, int val){

	if(node == NULL){
		Node *newNode = new Node(val);
		return newNode;
	}

	if(node->data > val){
		node->left = add(node->left, val);
		return node;
	}
	else if(node->data < val){
		node->right = add(node->right, val);
		return node;
	}
	else{
		return node;
	}
}