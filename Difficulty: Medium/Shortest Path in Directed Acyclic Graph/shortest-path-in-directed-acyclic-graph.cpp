class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
           // adj[edges[i][1]].push_back(edges[i][0]);
        }

        
        vector<int>dist(V, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>
        > pq;
        
        dist[0]=0;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            int d = t.first , n = t.second;
            if(d>dist[n]) continue;
            
            for(auto j: adj[n]){
                if(j.second+d < dist[j.first]){
                    dist[j.first] = j.second+d;
                    pq.push({dist[j.first] , j.first});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        
        return dist;
        
    }
};

