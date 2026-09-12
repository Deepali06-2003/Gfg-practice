class Solution {
  public:
  
  bool helper(vector<vector<int>>& adj, vector<int>& visited, int n, int p){
      
      visited[n]=1;
      
      for(auto j: adj[n]){
          
          if(visited[j]==-1){
              if(helper(adj, visited, j, n)==true) return true;
          }
          else if(visited[j]==1 && j != p) return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(V,-1);
        
        for(int i=0;i<V;i++){
            if(visited[i]==-1){
                if(helper(adj, visited, i, -1) == true) return true;
            }
        }
        
        return false;
    }
};