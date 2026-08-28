class Solution {
  public:
  
  bool helper(vector<vector<int>>& adj,vector<int>& visited , vector<int>& path_visited, int n){
      
      visited[n]=1;
      path_visited[n]=1;
      
      for(auto j: adj[n]){
          if(visited[j]==-1){
              if(helper(adj, visited, path_visited, j)==true) return true;
          }
          else if(visited[j]==1 && path_visited[j]==1) return true;
      }
      path_visited[n]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            //adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>visited(V, -1);
        vector<int>path_visited(V, -1);
        
        for(int i=0;i<V;i++){
            if(visited[i] == -1){
                if(helper(adj, visited, path_visited,i) == true) return true;
            }
        }
        return false;
    }
};