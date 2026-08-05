class Solution {
  public:
    bool checkEdge(vector<vector<int>>& adj, int u, int v) {
        // code here
        for(int i=0;i<adj.size(); i++){
            for(auto j: adj[i]){
                if((i == u && j == v) || (i == v && j == u)) return true;
            }
        }
        return false;
    }
};