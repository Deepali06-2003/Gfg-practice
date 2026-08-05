class Solution {
  public:
    bool checkPath(int V, vector<vector<int>>& edges, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        vector<int>visited(V, 0);
        
        q.push(src);
        visited[src]=1;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            if(x == dest) return true;
            
            for(auto j: adj[x]){
                if(visited[j]==0){
                    q.push(j);
                    visited[j]=1;
                }
            }
        }
        return false;
    }
};
