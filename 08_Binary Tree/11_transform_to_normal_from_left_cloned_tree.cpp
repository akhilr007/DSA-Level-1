// transform back from left cloned tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of transBackFromLeftClonedTree function. The function is expected to convert a left-cloned tree back to it's original form. The left cloned tree is dicussed in previous question. In a left-clone tree a new node for every node equal in value to it is inserted between itself and it's left child. For clarity check out the question video.
3. Input and Output is managed for you.

Input Format
Input is managed for you.

Output Format
Output is managed for you. 

      a                     a
    /   \                 /   \
   b     c    <-         a      c
  / \   / \             /      /  \
 d   e  f  g           b      c   g
                      / \    /   /
                     b   e  f   g
                    /   /  /
                   d   e  f
                  /
                 d
*/

Node* transBackFromLeftClonedTree(Node* node){

	if(node == NULL){

		return NULL;
	}

	node->left = transBackFromLeftClonedTree(node->left->left);
	node->right = transBackFromLeftClonedTree(node->right);

	return node;
}