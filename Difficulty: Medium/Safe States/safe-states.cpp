class Solution {
  public:
  
  bool dfs(vector<vector<int>>& adj , vector<int>& visit, vector<int>& path_visit,vector<int>& check, int node){
      check[node]=0;
      visit[node] = 1;
      path_visit[node] =1;
      
      for(auto j: adj[node]){
        if(visit[j]==0){
            if(dfs(adj, visit , path_visit ,check, j)== true){
                check[node]=0;
                return true;
            }
        }
        else if(visit[j]==1 && path_visit[j]==1){
            check[node]=0;
            return true;
        }
      }
      check[node]=1;
      path_visit[node]=0;
      return false;
  }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> res;
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int>visit(V, 0);
        vector<int>path_visit(V, 0);
        vector<int>check(V, 0);
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                dfs(adj , visit , path_visit , check , i);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1) res.push_back(i);
        }
        return res;
    }
};