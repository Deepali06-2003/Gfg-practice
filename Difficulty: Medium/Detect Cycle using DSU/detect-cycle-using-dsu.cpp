class Solution {
  public:
  
  bool dfs(vector<int> adj[], vector<int>& visited , int n, int parent){
      visited[n]=1;
      
      for(auto j: adj[n]){
          if(visited[j]==0){
              if(dfs(adj, visited, j, n)== true) return true;
          }
          else if(visited[j]==1 && j!=parent) return true;
      }
      return false;
  }
  
    bool detectCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>visited(V, 0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(adj, visited, i, -1)) return true;
            }
        }
        
        return false;
    }
};