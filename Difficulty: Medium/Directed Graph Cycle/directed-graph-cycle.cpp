class Solution {
  public:
  
  bool dfs(vector<vector<int>> & adj, vector<int>& visited, vector<int>& path_visit , int node){
      
      visited[node] =1;
      path_visit[node] =1;
      
      for(auto j : adj[node]){
          if(visited[j] == 0){
              if(dfs(adj , visited, path_visit , j) == true) return true;
          }
          else if(visited[j] == 1 && path_visit[j]==1) return true;
      }
      
      path_visit[node]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int>visited(V, 0);
        vector<int>path_visit(V, 0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if (dfs(adj, visited, path_visit, i)== true) return true;
            }
        }
        return false;
        
    }
};