// diameter of binary tree
/*
. You are given a partially written BinaryTree class.
2. You are required to complete the body of diameter1 function. The function is expected to return the number of edges between two nodes which are farthest from each other in terms of edges.
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
      30  40 60 70    diameter of binary tree = 6 

*/

// not so efficient solution -> O(n^2)

int height(Node* node){

	if(node == NULL) return -1;

	int lh = height(node->left);
	int rh = height(node->right);

	return max(lh, rh) + 1;
}

int diameter(Node* node){

	if(node == NULL) return 0;

	int ld = diameter(node->left);
	int rd = diameter(node->right);

	int dist = height(node->left) + height(node->right) + 2;

	int dia = max(dist, max(ld, rd));

	return dia;
}

// efficient solution ->O(n)

static int dia = 0;

int height(Node* node){

	if(node == NULL) return -1;

	int lh = height(node->left);
	int rh = height(node->right);

	int dist = lh + rh + 2;

	if(dist > dia){
		dia = dist;
	}

	int th = max(lh, rh) + 1;
	return th;
}

int diameter(Node* node){

	int ht = height(node);
	return dia;
}