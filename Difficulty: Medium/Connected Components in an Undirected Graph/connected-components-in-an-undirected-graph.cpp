class Solution {
  public:
  
  void helper(vector<vector<int>>& adj, vector<int>& visited, int n , int p, vector<int>& temp){
      
      visited[n]=1;
      temp.push_back(n);
      
      for(auto j: adj[n]){
          if(visited[j]==0){
              helper(adj, visited, j, n, temp);
          }
      }
  }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>>res;
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                
                vector<int>temp;
                helper(adj, visited, i, -1, temp);
                res.push_back(temp);
            }
        }
        return res;
    }
};
