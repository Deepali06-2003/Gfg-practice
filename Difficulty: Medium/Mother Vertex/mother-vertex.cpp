class Solution {
  public:
  
 void dfs(vector<vector<int>>& adj , vector<int>& visited, int n){
     visited[n]=1;
     
     for(auto j: adj[n]){
         if(visited[j]==0){
             dfs(adj, visited, j);
         }
     }
 }
 
 int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        int mother_vertex =-1;
        vector<int>visited(V, 0); 
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(adj, visited , i);
                mother_vertex = i;
            }
        }
        
        vector<int>visit(V, 0); 
        dfs(adj , visit, mother_vertex);
        for(int i=0;i<V;i++){
            if(visit[i]==0) return -1;
        }
        
        return mother_vertex;
    }
};