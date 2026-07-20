class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
      visited[node] =1;
      
      for(auto j: adjList[node]){
          if(visited[j]==0){
              dfs(j, adjList , visited);
          }
      }
  }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        
        for(int i=0;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>visited(V, 0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i, adjList , visited);
                ans++;
            }
        }
        
        return ans;
    }
};