// largest BST Subtree
/*
1. You are given a partially written BinaryTree class.
2. You are required to find the root of largest sub-tree which is a BST. Also, find the number of nodes in that sub-tree.
3. Input is managed for you. 

Note -> Please refer the question video for clarity.
Input Format
Input is managed for you.
Output Format
@

Constraints
Time complexity must be O(n)
Space should not be more than required for recursion (call-stack)

Sample Input
15
50 25 12 n n 37 n n 75 62 n n 87 n n

Sample Output
50@7
*/

class LBSTPair{
public:
	int mi;
	int ma;
	bool isBST;
	Node* lbstnode; // largest binary subtree node
	int size; // largest binary subtree size

	LBSTPair(int mi, int ma, bool isBST, Node* lbstnode, int size){
		this->mi = mi;
		this->ma = ma;
		this->isBST = isBST;
		this->lbstnode = lbstnode;
		this->size = size;
	}
};

LBSTPair largestBSTSubtree(Node* node){

	if(node == NULL){
		return LBSTPair(INT_MAX, INT_MIN, true, NULL, 0);
	}

	LBSTPair lp = largestBSTSubtree(node->left);
	LBSTPair rp = largestBSTSubtree(node->right);

	int mi = min(min(lp.mi, rp.mi), node->data);
	int ma = max(max(lp.ma, rp.ma), node->data);
	bool isBST = (lp.isBST == true) && (rp.isBST == true) && ((lp.ma < node->data) && (node->data < rp.mi));

	Node* lbstnode = NULL;
	int size = 0;

	if(isBST==true){
		lbstnode = node;
		size = lp.size + rp.size + 1;
	}
	else{
		if(lp.size > rp.size){
			lbstnode = lp.lbstnode;
			size = lp.size;
		}
		else{
			lbstnode = rp.lbstnode;
			size = rp.size;
		}
	}

	return LBSTPair(mi, ma, isBST, lbstnode, size);
}

LBSTPair ans = largestBSTSubtree(root);
cout << ans.lbstnode<<"@"<<ans.size<<endl;