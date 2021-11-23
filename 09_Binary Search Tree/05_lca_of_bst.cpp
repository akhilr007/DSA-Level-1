// lca of bst
/*
1. You are given a partially written BST class.
2. You are required to complete the body of lca function. "lca" function is expected to find the lowest commong ancestor of d1 and d2.
3. Input and Output is managed for you. 

Note -> Please watch the question video for clarity.

Input Format
Input is managed for you

Output Format
Output is managed for you
*/

int getLca(Node* node, int a, int b){

	if(node == NULL){
		return -1;
	}

	// if node data greater than both values, then go left
	if(node->data > a && node->data > b){
		return getLca(node->left, a, b);
	}
	else if(node->data < a && node->data < b){
		return getLca(node->right, a, b);
	}
	else{
		return node->data;
	}
}