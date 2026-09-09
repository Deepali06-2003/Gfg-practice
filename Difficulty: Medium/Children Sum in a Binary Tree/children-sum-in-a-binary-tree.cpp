/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root==NULL) return true;
        if(root->left ==NULL && root->right==NULL) return true;
        int s=0;
        if(root->left) s = s+ root->left->data;
        if(root->right) s = s+root->right->data;
        
        if( s!= root->data) return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};