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
    vector<int> bottomView(Node *root) {
        // code here
        //q-> node , level, vertex              map-> vertex, level, node
        
        queue<pair<Node* , pair<int, int>>>q;
        map<int , map<int, int>>mp;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto j = q.front();
            q.pop();
            
            int l = j.second.first , v = j.second.second;
            mp[v][l] = j.first->data;
            
            if(j.first->left) q.push({j.first->left, {l+1, v-1}});
            if(j.first->right) q.push({j.first->right, {l+1, v+1}});
        }
        
        vector<int> res;

        for (auto &v : mp) {

            // Last level = bottommost node
            auto it = v.second.rbegin();

            res.push_back(it->second);
        }

        return res;
        
    }
};