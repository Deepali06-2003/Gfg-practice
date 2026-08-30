class Solution {
  public:
  

  void dfs(int n, vector<int>& visited, vector<vector<int>>& adj, int d){
      
      visited[n]=1;
      if(n == d)return;
      
      for(auto j: adj[n]){
          if(visited[j]==0){
              dfs(j, visited, adj, d);
          }
      }
  }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            
            if(((u == c) && (v==d)) || ((u==d) && (v==c))) continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V, 0);
        dfs(c, visited, adj, d);
        
        if(visited[d]==0) return true;
        return false;
      
    }
};