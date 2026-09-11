/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
  void helper(Node* root, int k, Node*& ans){
      if(root==NULL)return;
      
      if(root->data <= k){
          ans = root;
          helper(root->right , k, ans);
      }
      else{
          helper(root->left , k, ans);
      }
  }
    int findMaxFork(Node* root, int k) {
        // code here
        if(root == NULL) return -1;
        Node* ans=NULL;
        helper(root, k, ans);
        
        if(ans == NULL) return -1;
        return ans->data;
    }
};