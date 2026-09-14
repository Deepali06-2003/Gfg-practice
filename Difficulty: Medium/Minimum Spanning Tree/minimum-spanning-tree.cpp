class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
       priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>>pq;
       //dist , node
       
       int sum =0;
       vector<int>dist(V, INT_MAX);
       vector<int>visited(V, -1);
       
       pq.push({0, 0});
       
       while(!pq.empty()){
           auto[d,n] = pq.top();
           pq.pop();
           
           if(visited[n]==1) continue;
           
           visited[n]=1;
           sum = sum + d;
           
           for(auto j : adj[n]){
               int cd = j.second;
               int cn = j.first;
               
               if(visited[cn]==-1 && dist[cn]> cd){
                   dist[cn] = cd;
                   pq.push({dist[cn] , cn});
               }
           }
       }
       
       return sum;
    }
};