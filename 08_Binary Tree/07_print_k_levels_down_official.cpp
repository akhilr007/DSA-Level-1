// print k levels down
/*
1. You are given a partially written BinaryTree class.
2. You are given a value k.
3. You are required to complete the body of printKLevelsDown function. The function is expected to print in different lines all nodes which are k level deep. Use preorder for printing.
4. Input is managed for you.

Input Format
Input is managed for you

Output Format
All nodes k-level deep printed in separated lines and visited in preorder

	       50
	     /    \
	  25        75
	 /  \      /   \
	12  37    62    87
	   /  \  /  \
      30  40 60 70  

 for k = 2, output :- 12 37 62 87
*/


void kLevelsDown(Node* node, int k){

	if(node == NULL) return;

	if(k == 0){
		cout << node->data << endl;
		return;
	}

	kLevelsDown(node->left, k-1);
	kLevelsDown(node->right, k-1);

}
