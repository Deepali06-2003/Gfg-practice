class Solution {
  public:
    vector<vector<int>> findInOutDegree(int V, vector<vector<int>>& edges) {
        // code here.   indegree , outdegree
        vector<vector<int>>ans(V, vector<int>(2, 0));
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            ans[u][1] += 1;
            ans[v][0] += 1;
        }
        return ans;
    }
};