class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>ind(V, 0);
        for(int i =0;i<V;i++){
            for(int j =0; j<adj[i].size();j++){
                int x = adj[i][j];
                ind[x]++;
            }
        }
        
        queue<int>q;
        vector<int>res;
        for(int i =0;i<ind.size();i++){
            if(ind[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            
            for(int i =0;i<adj[temp].size(); i++){
                int x = adj[temp][i];
                ind[x]--;
                if(ind[x] ==0)q.push(x);
            }
        }
        return res;
        
    }
};