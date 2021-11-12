// remove leaves nodes from binary tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of removeLeaves function. The function is expected to remove all leaf nodes from the tree.
3. Input and Output is managed for you. 

Input Format
Input is managed for you.

Output Format
Output is managed for you.


	       50
	     /    \
	  25        75
	 /  \      /   \
	12  37    62    87
	   /  \  /  \
      30  40 60 70   


25 <- 50 -> 75
. <- 25 -> 37
. <- 37 -> .
62 <- 75 -> .
. <- 62 -> .
*/

Node* removeLeaves(Node* node){

	if(node == NULL) return NULL;

	if(node->left == NULL && node->right == NULL){
		return NULL;
	}

	Node* lc = removeLeaves(node->left);
	node->left = lc;

	Node* rc = removeLeaves(node->right);
	node->right = rc;

	return node;
}