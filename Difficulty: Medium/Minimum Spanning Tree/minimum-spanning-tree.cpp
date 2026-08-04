class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            
            adj[u].push_back({v, wt});adj[v].push_back({u, wt});
        }
        
        vector<pair<int, int>>mst;
        vector<int>visited(V, 0);
        
           priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;
        
        int sum=0;
        pq.push({0, {0, -1}});  //wt, node parent
        
        while(!pq.empty()){
            
            auto temp = pq.top();
            pq.pop();
            
            int node = temp.second.first , wt = temp.first, p = temp.second.second;
            
            if(visited[node]==1) continue;
            
            visited[node]=1;
            sum = sum+wt;
            mst.push_back({p,node});
            
            for(auto j: adj[node]){
                if(visited[j.first] != 0) continue;
                else pq.push({j.second , {j.first, node}});
            }
        }
        
        //for(auto i: mst){
        //    cout<<i.first<<' '<<i.second<<endl;
        //}
        return sum;
    }
};