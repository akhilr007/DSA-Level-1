// tilt of a binary tree;
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of tilt function. The function is expected to set the value of data member "tilt". "tilt" of a node is the absolute value of difference between sum of nodes in it's left subtree and right subtree. "tilt" of the whole tree is represented as the sum of "tilt"s of all it's nodes.
3. Input and Output is managed for you. 

Note -> Please refer the video for clarity.

Input Format
Input is managed for you.

Output Format
Output is managed for you. 

*/
// using static variable
static int tilt = 0;
int tiltOfBinaryTree(Node* node){

	if(node == NULL) return 0;

	int lsum = tiltOfBinaryTree(node->left);
	int rsum = tiltOfBinaryTree(node->right);

	int ltilt = abs(lsum-rsum);
	tilt += ltilt;

	int ts = lsum + rsum + node->data;
	return ts;
}