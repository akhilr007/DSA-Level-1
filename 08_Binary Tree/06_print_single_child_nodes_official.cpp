//Print Single Child Nodes
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of printSingleChildNodes function. The function is expected to print in separate lines, all such nodes which are only child of their parent. Use preorder for traversal.
3. Input and Output is managed for you.

Input Format
Input is managed for you.

Output Format
Output is managed for you

Constraints
None

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
30
70
 
     50
   /    \
  25     75
 /  \    / 
12  37  62
    /   /
   30  60

   output 37 75 62
*/

void helper(Node* node){

	if(node == NULL){
		return;
	}

	if(node->left == NULL && node->right != NULL){
		cout << node->right->data<<endl;
	}
	else if(node->right == NULL && node->left != NULL){
		cout << node->left->data<<endl;
	}

	helper(node->left);
	helper(node->right);
}

void printSingleChildNodes(Node* node, Node* parent) {
    
    helper(node);

}
