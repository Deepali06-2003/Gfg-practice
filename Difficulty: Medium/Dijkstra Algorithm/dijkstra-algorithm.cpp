class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, edges[i][2]});
            adj[v].push_back({u, edges[i][2]});
        }
        
        vector<int>dist(V, INT_MAX);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            for(auto j : adj[node]){
                int n = j.first;
                int c_d = j.second;
                
                if(dist[n] > c_d+d){
                    dist[n] = c_d +d;
                    pq.push({dist[n] , n});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i] =-1;
        }
        return dist;
    }
};