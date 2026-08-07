class Solution {
  public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        // code here
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({ edges[i][1], edges[i][2]});
        }
        if(src == dst) return 0;
        
        vector<int>dist(n , INT_MAX);
        // stops , node , dist
        queue<pair<int, pair<int, int>>>q;
        
        q.push({0, {src , 0}});
        dist[src] = 0;
        
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int stops = temp.first , node = temp.second.first , d = temp.second.second;
            
            if(stops > k) continue;
            
            for(auto j: adj[node]){
                int n = j.first , c_d = j.second;
                
                if(c_d+d < dist[n] && (stops+1 <= k+1)){
                    
                    dist[n] = c_d +d;
                    q.push({stops+1, {n , dist[n] }});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        
        return dist[dst];
    }
};