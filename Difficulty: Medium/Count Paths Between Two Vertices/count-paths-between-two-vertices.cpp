

class Solution {
  public:
  
    int countPaths(int V, vector<vector<int>>& edges, int src, int dest) {
        // code here
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        
        vector<int>ways(V, 0);
        vector<int>indegree(V, 0);
        queue<int>q;
        
        for(int i=0;i<V;i++){
           for(auto j: adj[i]){
               indegree[j]++;
           }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        ways[src]=1;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            for(auto j:adj[n]){
                
                ways[j] = ways[j] + ways[n];
                
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        return ways[dest];
        
    }
};