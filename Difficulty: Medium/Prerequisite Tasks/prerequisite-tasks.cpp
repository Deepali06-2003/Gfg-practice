class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        // code here
        
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i].second].push_back(pre[i].first);
        }
        
        vector<int>indegree(n, 0);
        queue<int>q;
        vector<int>res;
        
        for(int i=0;i<n;i++){
            for(auto j: adj[i]) indegree[j]++; 
        }
        
        for(int i=0;i<n;i++){
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
        
        if(res.size()==n) return true;
       return false;
    }
};