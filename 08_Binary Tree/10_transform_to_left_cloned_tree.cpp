// transform to left cloned tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of createLeftCloneTree function. The function is expected to create a new node for every node equal in value to it and inserted between itself and it's left child. Check question video for clarity.
3. Input and Output is managed for you.

Input Format
Input is managed for you.

Output Format
Output is managed for you.

      a                     a
    /   \                 /   \
   b     c    ->         a      c
  / \   / \             /      /  \
 d   e  f  g           b      c   g
                      / \    /   /
                     b   e  f   g
                    /   /  /
                   d   e  f
                  /
                 d
*/ 

Node* createLeftCloneTree(Node* node){

	if(node == NULL) return NULL;


	Node* ln = createLeftCloneTree(node->left);

	Node* rn = createLeftCloneTree(node->right);

	node->right = rn;

	Node* cn = new Node(node->data);
	node->left = cn;
	cn->left = ln;

	return node;
}