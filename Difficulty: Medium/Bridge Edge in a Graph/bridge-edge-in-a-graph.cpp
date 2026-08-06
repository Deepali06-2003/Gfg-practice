class Solution {
  public:
  
  void dfs(vector<int>& visit, vector<vector<int>>& adj, int n){
      visit[n]=1;
      
      for(auto j: adj[n]){
          if(visit[j]==0)dfs(visit, adj, j);
      }
  }
  
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            if( (edges[i][0]==c && edges[i][1]==d) || (edges[i][0]==d && edges[i][1]==c) ) continue;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visit(V , 0);
        dfs(visit, adj, c);
        
        return (visit[d]==0);
    }
};