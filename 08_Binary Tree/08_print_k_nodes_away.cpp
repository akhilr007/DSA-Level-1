// print nodes k distance away
/*
1. You are given a partially written BinaryTree class.
2. You are given a value data and a value k.
3. You are required to complete the body of printKNodesFar function. The function is expected to print all nodes which are k distance away in any direction from node with value equal to data.
4. Input is managed for you.

Input Format
Input is managed for you

Output Format
All nodes which are k distance away in any direction from node with value equal to data, each in a separate line
*/

vector<Node*> nodeToRootPath(Node* node, int data){

	if(node == NULL){
		return {};
	}

	if(node->data == data){
		vector<Node*> v;
		v.push_back(node);
		return v;
	}

	vector<Node*> lc = nodeToRootPath(node->left, data);
	if(lc.size() > 0){
		lc.push_back(node);
		return lc;
	}

	vector<Node*> rc = nodeToRootPath(node->right, data);
	if(rc.size() > 0){
		rc.push_back(node);
		return rc;
	}

	return {};
}

void printKLevelsDown(Node* node, int k, Node* prbht){

	if(node == NULL || node == prbht){
		return;
	}

	if(k == 0){
		cout << node->data << endl;
		return;
	}

	printKLevelsDown(node->left, k-1, prbht);
	printKLevelsDown(node->right, k-1, prbht);
}

printKNodesFar(Node* node, int data, int k){

	// get all the nodes from root to node path 
	vector<Node*> list = nodeToRootPath(node, data);
	Node* prbht = NULL;

	for(int i=0; i<list.size(); i++){

		// get access to all the node in the list
		Node* child = list[i];
		printKLevelsDown(child, k-i, prbht);
		prbht = child;
	}
}