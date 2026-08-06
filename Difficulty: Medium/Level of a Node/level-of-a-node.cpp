class Solution {
  public:
    int nodeLevel(int V, vector<vector<int>>& edges, int x) {
        // code here
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int, int>>q;
        vector<int>dist(V, INT_MAX);
        
        if(x == 0) return 0;
        
        q.push({0, 0});
        dist[0]=0;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int n = temp.first , d = temp.second;
            
            if(dist[n]<d)continue;
            
            for(auto j: adj[n]){
                if(dist[j] > d+1){
                    if(x == j) return d+1;
                    dist[j] = d+1;
                    q.push({j, d+1});
                }
            }
        }
        return -1;
    }
};