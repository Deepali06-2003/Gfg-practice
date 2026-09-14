class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1], w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int>dist(V, INT_MAX);
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        dist[src]=0;
        
        while(!pq.empty()){
            auto[wt, n] = pq.top();
            pq.pop();
            
            if(wt > dist[n]) continue;
            
            for(auto j: adj[n]){
                int w = j.second;
                                                   int c = j.first;
                if(dist[c] > dist[n]+w){
                    dist[c] = dist[n]+w;
                    pq.push({dist[c] , c});
                }
            }
        }
        
        for(int& i :dist){
            if(i==INT_MAX) i = -1;
        }
        return dist;
        
    }
};