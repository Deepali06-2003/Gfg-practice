class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            
            adj[u].push_back({v, wt});adj[v].push_back({u, wt});
        }
        
        //pair<int,pair<int, int>> // wt , node, parent
       priority_queue< pair<int,pair<int, int>> , vector< pair<int,pair<int, int>>> , greater< pair<int,pair<int, int>>>>pq;
       int sum = 0;
       vector<pair<int, int>>mst;
       
       vector<int>visited(V, 0);
       
       pq.push({0,{0,-1}});
       
       
       while(!pq.empty()){
           
           auto t = pq.top();
           pq.pop();
           
           int wt = t.first , v = t.second.first , u = t.second.second;
           
           if(visited[v]==1) continue;
           
           visited[v]=1;
           sum = sum+wt;
           mst.push_back({u, v});
           
           for(auto j : adj[v]){
               if(visited[j.first]==0){
                   pq.push({j.second , {j.first, v}});
               }
           }
       }
       
       return sum;
    }
};