// Find And Nodetorootpath In Binary Tree
/*
1. You are given a partially written BinaryTree class.
2. You are given an element.
3. You are required to complete the body of find and nodeToRoot function. The functions are expected to 
    3.1. find -> return true or false depending on if the data is found in binary tree.
    3.2. nodeToRoot -> returns the path from node (correspoding to data) to root in 
    form of an arraylist (root being the last element)
4. Input iand Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
30

Sample Output
true
[30, 37, 25, 50]
*/
bool find(Node* node, int data) {
      
    if(node == NULL){
        return false;
    }
    
    if(node->data == data){
        return true;
    }
    
    bool lc = find(node->left, data);
    if(lc == true){
        return true;
    }
    
    bool rc = find(node->right, data);
    if(rc == true){
        return true;
    }
    
    return false;
}

vector<int> nodeToRootPath(Node* node, int data) {
    
    if(node == NULL){
        return {};
    }
    
    if(node->data == data){
        vector<int> list;
        list.push_back(data);
        return list;
    }
    
    vector<int> lc = nodeToRootPath(node->left, data);
    if(lc.size() > 0){
        lc.push_back(node->data);
        return lc;
    }
    
    vector<int> rc = nodeToRootPath(node->right, data);
    if(rc.size() > 0){
        rc.push_back(node->data);
        return rc;
    }
    
    return {};
}
