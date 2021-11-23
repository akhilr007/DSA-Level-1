// replace with sum of larger
/*
1. You are given a partially written BST class.
2. You are required to complete the body of rwsol function. "rwsol" function is expected to replace a node's value with sum of all nodes greater than it.
3. Input and Output is managed for you. 

Input Format
Input is managed for you

Output Format
Output is managed for you

*/

int sum = 0;
void rwsol(Node* node){
	
	// reverse inorder traversal
	if(node == NULL) return;

	rwsol(node->right);

	// self work
	int temp = node->data;
	node->data = sum;
	sum += temp;

	rwsol(node->left);
}