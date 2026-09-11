/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
  void helper(Node* root, int k, Node*& ans){
       if(root==NULL)return;

       if(root->data >= k){
           ans = root;
           helper(root->left , k, ans);
       }
       else{
           helper(root->right , k, ans);
       }
   }
   
    int findCeil(Node* root, int x) {
        // code here
        if(root == NULL) return -1;
                Node* ans=NULL;
                helper(root, x, ans);

                if(ans == NULL) return -1;
                return ans->data;
    }
};
