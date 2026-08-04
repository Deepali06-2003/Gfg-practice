class Solution {
  public:
    int findCity(int n, vector<vector<int>>& edges, int dis) {
        // code here
        vector<vector<int>>adj(n, vector<int>(n, INT_MAX));
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1] , w = edges[i][2];
            adj[u][v]=w;
            adj[v][u]=w;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i == j) adj[i][j]=0;
                    else if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX) continue;
                    
                    else  adj[i][j] = min(adj[i][j] , adj[i][k]+adj[k][j]);
                }
            }
        }
        
       int c_min = INT_MAX , ans=-1;
        for(int i=0;i<n;i++){
            int city =0;
            for(int j=0;j<n;j++){
                if( adj[i][j]<= dis) city+= 1;
            }
            if(city <= c_min){
                c_min = city;
                ans = i;
            }
        }
        
        return ans;
    }
};
