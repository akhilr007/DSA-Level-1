// is balanced tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is balanced. A binary tree is balanced if for every node the gap between height's of it's left and right subtree is not more than 1.
3. Input is managed for you. 

Note -> Please refer the question video for clarity.

Input Format
Input is managed for you.

Output Format
true if the tree is balanced, false otherwise

*/
static bool isBal = true;

int height(Node* node){

	if(node == NULL) return -1;

	int lh = height(node->left);
	int rh = height(node->right);

	int bf = abs(lh-rh);

	if(bf >= 2){
		isBal = false;
	}

	return max(lh, rh) + 1;
}

bool isBalanced(Node* node){

	int ht = height(node);
	return isBal;
}