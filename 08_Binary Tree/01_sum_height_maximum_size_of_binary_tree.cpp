// Size, Sum, Maximum And Height Of A Binary Tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of size, sum, max and height function. The functions are expected to
    2.1. size - return the number of nodes in BinaryTree
    2.2. sum - return the sum of nodes in BinaryTree
    2.3. max - return the highest node in BinaryTree
    2.4. height - return the height of tree in terms of edges
3. Input and Output is managed for you.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
None

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
9
448
87
3
*/

int size(Node* node)
{
   int ts = 0;
   if(node == NULL) return 0;
   
   int ls = size(node->left);
   int rs = size(node->right);
   ts = ls + rs + 1;
   
   return ts;
   
}

int height(Node* node)
{
    if(node == NULL) return -1;
    
    int lht = height(node->left);
    int rht = height(node->right);
    
    int tht = max(lht, rht) + 1;
    
    return tht;
}

int maximum(Node* node)
{
    if(node == NULL) return INT_MIN;
    
    int lmax = maximum(node->left);
    int rmax = maximum(node->right);
    
    return max(max(lmax, rmax), node->data);
}

int sum(Node* root)
{
    if(root == NULL) return 0;
    
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    
    int tsum = lsum+rsum + root->data;
    
    return tsum;
}
