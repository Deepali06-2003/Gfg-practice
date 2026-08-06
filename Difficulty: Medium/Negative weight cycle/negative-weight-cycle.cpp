class Solution {
  public:
  

    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Code here
        
        
        vector<int>dist(n, 0);
        
        
        for(int i=0;i<n-1;i++){
            for(auto e : edges){
                int u = e[0] , v = e[1] , w = e[2];
                
                if(dist[u]+w < dist[v]) dist[v]=dist[u]+w;
            }
        }
        
        for(auto e : edges){
                int u = e[0] , v = e[1] , w = e[2];
                
                if(dist[u]+w < dist[v]) return 1;
            }
        return 0;
    }
};