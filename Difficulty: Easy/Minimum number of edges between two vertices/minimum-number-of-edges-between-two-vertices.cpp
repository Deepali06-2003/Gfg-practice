class Solution {
  public:
    int minEdges(int V, vector<vector<int>>& edges, int u, int v) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(u == v) return 0;
        
        queue<pair<int,int>>q;
        vector<int>visited(V, 0);
        
        q.push({u, 0});
        visited[u]=1;
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            for(auto j : adj[x.first]){
                if(visited[j]==0){
                    
                    if(j == v) return x.second+1;
                    
                    visited[j]=1;
                    q.push({j, x.second+1});
                }
            }
        }
        
        return -1;
        
    }
};
