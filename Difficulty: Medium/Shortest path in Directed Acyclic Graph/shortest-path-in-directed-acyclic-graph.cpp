class Solution {
  public:
  
  void helper(vector<vector<pair<int, int>>>& adj, int V, vector<int>& topo){
      
      vector<int>indegree(V, 0);
      queue<int>q;
      
      for(int i=0;i<adj.size();i++){
          for(auto j: adj[i])   
            indegree[j.first]++;
      }
      
      for(int i=0;i<V;i++){
          if(indegree[i]==0) q.push(i);
      }
      
      while(!q.empty()){
          int x = q.front();
          q.pop();
          
          topo.push_back(x);
          
            for(auto j : adj[x]){
                indegree[j.first]--;
                if(indegree[j.first] == 0)
                    q.push(j.first);
            }
      }
  }
  
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int, int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        vector<int>topo;
        helper(adj, V, topo);
        
        vector<int>dist(V, INT_MAX);
        
        int x = topo[0];
        dist[x]=0;
        
        for(int i=0;i<V;i++){
            int node = topo[i];
            int c_dist = dist[node];
            
            if (c_dist == INT_MAX)  continue;
            
            for(auto j: adj[node]){
                int n = j.first;
                int d = j.second;
                
                dist[n] = min(dist[n], c_dist+d);
            }
        }
        
        for(int i =0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};
