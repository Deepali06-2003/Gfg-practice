/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
  void helper(Node* root, vector<vector<int>>& res, vector<int>curr){
     if(root == NULL)return;
     
     curr.push_back(root->data);
     if(root->left==NULL && root->right==NULL){
         res.push_back(curr);
     }
     helper(root->left, res, curr);
     helper(root->right, res, curr);
  }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>>res;
        vector<int> curr;
        helper(root, res, curr);
        return res;
    }
};