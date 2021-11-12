//Iterative Pre, Post And Inorder Traversals Of Binary Tree
/*
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of iterativePrePostInTraversal function. The function is expected to print pre order, in order and post order of the tree in separate lines (first pre, then in and finally post order). All elements in an order must be separated by a space.
3. Input is managed for you.

Input Format
Input is managed for you

Output Format
pre order (elements separated by space)
in order (elements separated by space)
post order (elements separated by space)

Constraints
None

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
50 25 12 37 30 75 62 70 87 
12 25 30 37 50 62 70 75 87 
12 30 37 25 70 62 87 75 50 
*/

void iterativePrePostInTraversal(Node* node) {
    
    if(node == NULL) return;
    
    string pre = "";
    string post = "";
    string in = "";
    
    stack<pair<Node*, int>> st;
    st.push({node, 0});
    
    while(st.size() > 0){
        
        int state = st.top().second;
        
        if(state == 0){
            // pre
            pre += to_string(st.top().first->data) + " ";
            st.top().second++;
            
            if(st.top().first->left != NULL){
                st.push({st.top().first->left, 0});
            }
        }
        else if(state == 1){
            // in
            in += to_string(st.top().first->data) + " ";
            st.top().second++;
            
            if(st.top().first->right != NULL){
                st.push({st.top().first->right, 0});
            }
        }
        else{
            //post
            post += to_string(st.top().first->data) + " ";
            st.pop();
        }
    }
    
    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
}
