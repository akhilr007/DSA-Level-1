// remove node from bst
/*
1. You are given a partially written BST class.
2. You are required to complete the body of remove function. "remove" function is expected to remove a new node with given data to the tree and return the new root.
3. Input and Output is managed for you. 

Note -> Please watch the question video to figure out the algorithm required for deletion. It specifies some requirements of the question as well.

Input Format
Input is managed for you

Output Format
Output is managed for you
*/

int getMax(Node* node, int data){

	if(node->right == NULL){
		return node->data;
	}

	return getMax(node->right, data);
}

Node* remove(Node* node, int data){
	
	if(node == NULL){
		return NULL;
	}

	if(node->data > data){
		node->left = remove(node->left, data);
	}
	else if(node->data < data){
		node->right = remove(node->right, data);
	}
	else{

		// if it has no child, then simply return null
		if(node->left == NULL && node->right == NULL){
			return NULL;
		}
		// it it has only left child 
		else if(node->left == NULL){
			return node->right;
		}
		// if it has only right child
		else if(node->right == NULL){
			return node->left;
		}
		// if it has both the child, then calculate max of left subtree and replace the node with lmax
		// then delete the lmax node 
		else{
			int lmax = getMax(node->left, data);
			node->data = lmax;
			node->left = remove(node->left, lmax);
		}
	}

	return node;
}