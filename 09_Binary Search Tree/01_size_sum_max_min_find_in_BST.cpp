//Size, Sum, Max, Min, Find In Bst
/*
1. You are given a partially written BST class.
2. You are required to complete the body of size, sum, max, min and find function. The functions are expected to:
    2.1. size - return the number of nodes in BST
    2.2. sum - return the sum of nodes in BST
    2.3. max - return the value of node with greatest value in BST
    2.4. min - return the value of node with smallest value in BST
    2.5. find - return true if there is node in the tree equal to "data"

3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you
*/

int size(Node* node){

    if(node == NULL) return 0;

    int lsize = size(node->left);
    int rsize = size(node->right);

    int ts = lsize + rsize + 1;
    return ts;
}

int sum(Node* node){

    if(node == NULL) return 0;

    int lsum = sum(node->left);
    int rsum = sum(node->right);

    int tsum = lsum + rsum + node->data;
    return tsum;
}

int maximum(Node* node){

    if(node->right == NULL){
        return node->data;
    }
    else{
        int rans = maximum(node->right);
        return rans;
    }
}

int minimum(Node* node){

    if(node->left == NULL){
        return node->data;
    }
    else{
        int rans = minimum(node->left);
        return rans;
    }
}

bool find(Node* node, int data){

    if(node == NULL){
        return false;
    }

    if(node->data == data){
        return true;
    }
    else if(node->data < data){
        bool lc = find(node->right, data);
        if(lc == true){
            return true;
        }
    }
    else{
        bool rc = find(node->left, data);
        if(rc == true){
            return true;
        }
    }

    return false;
}