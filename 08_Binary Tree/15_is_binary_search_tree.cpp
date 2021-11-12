// is a binary search tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is a Binary Search Tree (BST) as well. In a BST every node has a value greater than all nodes on it's left side and smaller value than all node on it's right side.
3. Input is managed for you. 

Note -> Please refer the question video for clarity.

Input Format
Input is managed for you.

Output Format
true if the tree is a BST, false otherwise
*/

class bst{
public:
	int mi;
	int ma;
	bool isBST;

	bst(int mi, int ma, bool isBST){
		this->mi = mi;
		this->ma = ma;
		this->isBST = isBST;
	}
	
};

bst BST(Node* node){

	if(node == NULL){
		return BST(INT_MAX, INT_MIN, true);
	}

	bst lp = BST(node->left);
	bst rp = BST(node->right);

	int mi = min(min(lp.mi, rp.mi), node->data);
	int ma = max(max(lp.ma, rp.ma), node->data);

	bool isBST = (lp.isBST == true) && (rp.isBST == true) && ((lp.ma < node->data) && (node->data < rp.mi));

	return BST(mi, ma, isBST);
}