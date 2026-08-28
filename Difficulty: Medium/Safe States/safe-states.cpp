class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            //adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>indegree(V, 0);
        queue<int>q;
        for(int i=0;i<V;i++){
            for(auto j: adj[i]) indegree[j]++;
        }
        
        for( int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>res;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            res.push_back(n);
            
            for(auto j: adj[n]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};