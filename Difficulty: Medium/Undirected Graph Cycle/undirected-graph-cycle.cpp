class Solution {
  public:
  bool dfs(vector<vector<int>>& adj , vector<int>& visited , int x, int parent){
      
      visited[x] =1;
      for(auto j : adj[x]){
         
          if(!visited[j]){
              if( dfs(adj, visited, j, x))return true;
          }
          else if(j != parent)return true;
      }
      return false;
  }
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(auto& p : edges){
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
        }
        
        vector<int>visited(V, 0);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj , visited , i, -1))return true;
            }
        }
        return false;
    }
};




