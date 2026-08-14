class Solution {
  public:
  
  int timer=1;
  
  void dfs(vector<vector<int>>& adj, vector<int>& visited,
           vector<int>& t_insert, vector<int>& lowest,vector<int>& mark, int n, int parent){
               
               visited[n]=1;
               t_insert[n] = lowest[n] = timer;
               timer++;
               int child =0;
               
               for(auto j: adj[n]){
                   if(j == parent) continue;
                   
                   else if(visited[j]==0){
                       dfs(adj, visited, t_insert, lowest, mark, j, n);
                       lowest[n] = min(lowest[n], lowest[j]);
                       
                       if(lowest[j] >= t_insert[n] && parent !=-1) mark[n]=1;
                       child++;
                   }
                   else{
                       lowest[n] = min(lowest[n], t_insert[j]);
                   }
               }
               if(child > 1 && parent ==-1) mark[n]=1;
           }
           
           
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // code here
        int n = V;
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n, 0);
        vector<int> t_insert(n);
        vector<int> lowest(n);
        vector<int>mark(n, 0);
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adj, visited, t_insert, lowest, mark , i, -1 );
            }
        }
       vector<int> ans;

       for(int i = 0; i < n; i++){
           if(mark[i] == 1)
               ans.push_back(i);
       }

       if(ans.empty()) return {-1};

       return ans;
    }
};