class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>visited(V , 0);
        
        pq.push({0 , 0});
        int sum =0;
        
        while(!pq.empty()){
            
            auto t = pq.top();
            pq.pop();
            
            int w = t.first;
            int node = t.second;
            
            if(visited[node])continue;
            
             visited[node] = 1;
            sum += w;
        
            for(auto &j : adj[node]){
                int ed_n = j.first;   // corrected
                int wt = j.second;    // corrected
                
                if(!visited[ed_n])   pq.push({wt, ed_n});
            }
        }
        
        return sum;
    }
};