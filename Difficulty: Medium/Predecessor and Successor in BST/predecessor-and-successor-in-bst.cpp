/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */



class Solution {
  public:
  void preorder(Node* root, int key, Node*& pre){
      if(root == NULL) return;
      
      if(key > root->data){
          pre = root;
          preorder(root->right, key, pre);
      }
      else{
          preorder(root->left, key, pre);
      }
  }
  
  void inorder(Node* root, int key, Node*& in){
      if(root == NULL) return;
      
      if(key < root->data){
          in = root;
          inorder(root->left, key, in);
      }
      else{
         inorder(root->right, key,in);
      }
  }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root == NULL) return {NULL, NULL};
        
        vector<Node*>res;
        
        Node* pre = NULL;
        preorder(root, key, pre);
        
        Node* in = NULL;
        inorder(root, key, in);
        
        res.push_back(pre);
        res.push_back(in);
        
        return res;
    }
};