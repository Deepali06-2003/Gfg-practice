class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>res;
        
        queue<int>q;
        vector<int>visit(n, 0);
        
        q.push(0);
        visit[0]=1;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            res.push_back(x);
            
            for(auto j: adj[x]){
                if(visit[j]==0){
                    visit[j]=1;
                    q.push(j);
                }
            }
        }
        return res;
        
    }
};