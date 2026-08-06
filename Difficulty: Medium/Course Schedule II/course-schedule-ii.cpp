class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>indegree(n, 0);
        for(int i=0;i<n;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>res;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            res.push_back(x);
            
            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        if (res.size() != n)
            return {};
        return res;
    }
};