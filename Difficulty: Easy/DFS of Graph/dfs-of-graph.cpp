class Solution {
  public:
  
  void dfs(vector<vector<int>>& adj, vector<int>& visit, int node, vector<int>& res){
      
      visit[node]=1;
      res.push_back(node);
      
      for(auto j : adj[node]){
          if(visit[j]==0){
              dfs(adj, visit, j, res);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int>visit(V, 0);
        
        vector<int>res;
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                dfs(adj, visit , i, res);
            }
        }
        return res;
    }
};