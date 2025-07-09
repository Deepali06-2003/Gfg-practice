class Solution {
  public:
    bool isLeaf(Node* root)
    {
        return root->left == NULL && root->right == NULL;
    }
    
    void leafNode(Node* root , vector<int>& res){
        if(root== NULL){
            return;
        }
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        leafNode(root->left , res);
        leafNode(root->right , res);
    }
    
    void leftView(Node* root, vector<int>&res){
        if(root== NULL || isLeaf(root)){
            return;
        }
        res.push_back(root->data);
        if(root->left)
            leftView(root->left , res);
        else
            leftView(root->right , res);
    }
    
    void rightView(Node* root , vector<int>& res){
        if(root== NULL || isLeaf(root)){
            return;
        }
        if(root->right)
            rightView(root->right, res);
        else
            rightView(root->left, res);
        res.push_back(root->data);  // add after recursion for reverse order
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        leftView(root->left , res);     // ✅ corrected from root->right to root->left
        leafNode(root , res);           // all leaves
        rightView(root->right , res);   // right boundary in reverse

        return res;
    }
};
