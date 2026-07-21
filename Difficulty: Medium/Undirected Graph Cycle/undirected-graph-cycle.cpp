class Solution {
  public:
  
  bool IsLoop(vector<vector<int>>& adjList, vector<int>& visited, int node){
      visited[node]=1;
                //node, parent
      queue<pair<int, int>>q;
      
      q.push({node, -1});
      
      while(!q.empty()){
          int temp = q.front().first;
          int parent = q.front().second;
          
          q.pop();
          
          for(auto j : adjList[temp]){
              if(visited[j]==0){
                  visited[j]=1;
                  q.push({j, temp});
              }
              else if(visited[j]==1 && j != parent) return true;
          }
      }
      
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adjList(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>visited(V, 0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(IsLoop(adjList, visited , i)) return true;;
            }
        }
        return false;
        
    }
};