class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>res;
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int>indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            
            int x = q.front();
            q.pop();
            
            res.push_back(x);
            
            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        
        return res;
    }
};