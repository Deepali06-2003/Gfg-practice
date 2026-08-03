class Solution {
  public:
  
  bool isSafe(vector<vector<int>>& adj ,int color, vector<int>& visited, int node){
    
     for(auto j: adj[node]){
         if(visited[j] != -1 && visited[j] == color) return false;
     }
     return true;
  }
  
  bool helper(vector<vector<int>>& adj , vector<int>& visited , int m , int v ,int node){
      
      if(node == v) return true;
      
      for(int c = 1;c<=m;c++){
          if(isSafe(adj , c , visited, node)){
              visited[node] = c;
              if(helper(adj , visited, m , v , node+1)) return true;
              visited[node] = -1;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        for(int i=0; i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int>visited(v, -1);
        return helper(adj , visited , m , v ,0);
        
        
    }
};