/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int c=0;
        if(root== NULL){
            return 0;
        }
        if(root->left == NULL and root->right == NULL){
            c++;
        }
        c= c+ countLeaves(root->left)+ countLeaves(root->right);
        return c;
    }
};