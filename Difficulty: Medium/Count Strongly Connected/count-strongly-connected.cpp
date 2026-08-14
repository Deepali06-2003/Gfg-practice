class Solution {
  public:
  
  void dfs(vector<vector<int>>& adj, vector<int>& visited, int n, stack<int>& st){
      visited[n]=1;
      for(auto j: adj[n]){
          if(visited[j]==0) dfs(adj, visited, j, st);
      }
      st.push(n);
  }
  
  void helper(vector<vector<int>>& Radj, vector<int>& visited, int n){
      visited[n]=1;
      
      for(auto j: Radj[n]){
          if(visited[j]==0) helper(Radj, visited, j);
      }
  }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        vector<vector<int>>Radj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            Radj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(V, 0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(adj, visited, i, st);
            }
        }
        
        for(int i=0;i<V;i++) visited[i]=0;
        
        int ans=0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(visited[x]==0){
                ans++;
                helper(Radj, visited, x);
            }
        }
        return ans;
    }
};