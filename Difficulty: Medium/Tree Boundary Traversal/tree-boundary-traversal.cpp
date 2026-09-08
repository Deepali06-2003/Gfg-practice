/* Node Structure
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
  
  void left(Node *root, vector<int>& res){
       if(root == NULL) return;
       
       if (root->left != NULL || root->right != NULL)
            res.push_back(root->data);

        if (root->left)
           left(root->left, res);
       else
            left(root->right, res);
  }
  void bottom(Node *root, vector<int>& res){
      if(root == NULL) return;
      
      bottom(root->left, res);
      if(root->left==NULL && root->right==NULL) res.push_back(root->data);
      bottom(root->right, res);
  }
  
  void right(Node *root, vector<int>& curr){
       if(root == NULL) return;
       
       if(root->left != NULL || root->right != NULL) curr.push_back(root->data);
       
       if(root->right)
        right(root->right, curr);
       else
        right(root->left, curr);
  }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        //bottom 
        // left
        //right
        
        vector<int>res;
        res.push_back(root->data);
        if(root->left == NULL && root->right ==NULL) return res;
        
        left(root->left, res);
        bottom(root, res);
        
        vector<int>curr;
        right(root->right, curr);
        reverse(curr.begin(), curr.end());
        
        for(int i=0;i<curr.size();i++) res.push_back(curr[i]);
        return res;
    }
};