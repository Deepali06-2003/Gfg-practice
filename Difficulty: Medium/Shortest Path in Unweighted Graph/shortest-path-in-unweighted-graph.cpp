class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>dist(V, INT_MAX);
        queue<int>q;
        
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto j: adj[x]){
                if(dist[j] > dist[x]+1){
                    dist[j] = dist[x]+1;
                    q.push(j);
                }
            }
        }
        
        if(dist[dest]==INT_MAX) return -1;
        return dist[dest];
    }
};
