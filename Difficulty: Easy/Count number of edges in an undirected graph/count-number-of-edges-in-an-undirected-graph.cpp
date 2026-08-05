class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        // code here
        
        int ans=0;
        for(int i=0;i<adj.size();i++){
            for( auto j : adj[i]){
                ans++;
            }
        }
        return ans/2;
    }
};