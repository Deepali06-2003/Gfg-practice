class Solution {
  public:
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0]; int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V, -1);
        queue<int>q;
        
        q.push(0);
        visited[0]=0;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            for(auto j: adj[n]){
                if(visited[j]==-1){
                    if(visited[n]==0) visited[j]=1;
                    else visited[j]=0;
                    q.push(j);
                }
                else if(visited[j]!=-1 && visited[j]==visited[n]) return false;
            }
        }
        return true;
    }
};