class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>indegree(V, 0);
        for(int i =0;i<V;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            res.push_back(x);
            
            for(auto i: adj[x]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(res.size()==V)return false;
        return true;
    }
};