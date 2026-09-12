class Solution {
  public:
    
    void helper(vector<vector<int>>& adj, vector<int>& visited, int n , vector<int>& res){
        visited[n]=1;
        res.push_back(n);
        
        for(auto j : adj[n]){
            if(visited[j]==-1){
                helper(adj, visited, j, res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size();
        vector<int> visited(n, -1);
        
        vector<int>res;
        
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                helper(adj, visited, i, res);
            }
        }
        
        return res;
    }
};