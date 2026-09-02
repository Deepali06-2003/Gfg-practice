class Solution {
  public:
  
  void helper( vector<vector<int>>& adj, vector<int>& visit, int n, stack<int>& st){
      visit[n]=1;
      
      for(auto j: adj[n]){
          if(visit[j]==0){
              helper(adj, visit, j, st);
          }
      }
      st.push(n);
  }
  
  void dfs( vector<vector<int>>& reverseAdj, vector<int>& visit, int n, vector<int>& curr){
      visit[n]=1;
      curr.push_back(n);
      
      for(auto j: reverseAdj[n]){
          if(visit[j]==0){
              dfs(reverseAdj, visit, j, curr);
          }
      }
  }
  
    vector<vector<int>> tarjans(int V, vector<vector<int>>& adj) {
        // code here
        
        vector<int>visit(V, 0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(visit[i]==0) helper(adj, visit, i, st);
        }
        
        vector<vector<int>> reverseAdj(V);

        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                reverseAdj[j].push_back(i);
            }
        }

        fill(visit.begin(), visit.end(), 0);for(int i=0;i<V;i++) visit[i]=0;
        
        vector<vector<int>>res;
        vector<int>curr;
        
        while(!st.empty()){
            curr.clear();
            
            int x = st.top();
            st.pop();
            
            if(visit[x]==0){
                dfs(reverseAdj, visit, x, curr);
                sort(curr.begin(), curr.end());
                res.push_back(curr);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};