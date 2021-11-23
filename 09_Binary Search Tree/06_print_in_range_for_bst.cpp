// print in range
/*
1. You are given a partially written BST class.
2. You are required to complete the body of pir function. "pir" function is expected to print all nodes between d1 and d2 (inclusive and in increasing order).
3. Input and Output is managed for you. 

Note -> Please watch the question video for clarity.

Input Format
Input is managed for you

Output Format
Output is managed for you
*/

// r1 -> range1 and r2 -> range2
void printInRange(Node* node, int r1, int r2){

	if(node == NULL) return;

	if(node->data > r1 && node->data > r2){
		printInRange(node->left, r1, r2);
	}
	else if(node->data < r1 && node->data < r2){
		printInRange(node->right. r1, r2);
	}
	else{
		printInRange(node->left, r1, r2);
		cout << node->data << endl;
		printInRange(node->right, r1, r2);
	}
}