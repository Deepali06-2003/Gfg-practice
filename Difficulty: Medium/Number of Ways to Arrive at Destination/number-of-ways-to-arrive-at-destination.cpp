class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];
            
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        //pq>dist , node
        
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        vector<int>dist(V, INT_MAX);
        vector<int>ways(V, 0);
        
        pq.push({0, 0});
        dist[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            int d = t.first , node = t.second;
            
            if(dist[node] < d) continue;
            
            for(auto j : adj[node]){
                int c_d = j.second;
                int n = j.first;
                
                if(dist[n] > c_d+d){
                    dist[n] = c_d+d;
                    ways[n] = ways[node];
                    
                    pq.push({ dist[n] , n});
                    
                }
                else if(dist[n] == c_d+d){
                    ways[n] = ways[n]+ways[node];
                }
            }
        }
        return ways[V-1];
        
    }
};