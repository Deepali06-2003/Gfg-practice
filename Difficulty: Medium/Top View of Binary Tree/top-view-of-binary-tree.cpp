/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
       queue<pair<Node*, pair<int, int>>> q;
          // node -> {level, horizontal distance}

          map<int, int> mp;
          // horizontal distance -> first node

          q.push({root, {0, 0}});

          while(!q.empty()) {

              auto j = q.front();
              q.pop();

              Node* node = j.first;

              int level = j.second.first;
              int horizontal = j.second.second;

              // Store only the first node at this horizontal distance
              if(mp.find(horizontal) == mp.end()) {
                  mp[horizontal] = node->data;
              }

              if(node->left)
                  q.push({node->left, {level + 1, horizontal - 1}});

              if(node->right)
                  q.push({node->right, {level + 1, horizontal + 1}});
          }

          vector<int> res;

          for(auto &x : mp) {
              res.push_back(x.second);
          }

          return res;
    }
};


   