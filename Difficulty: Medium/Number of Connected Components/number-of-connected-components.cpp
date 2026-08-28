class Solution {
  public:
    
    void helper(vector<vector<int>>& adjList, vector<int>& visited, int n){
        visited[n]=1;
        
        for(auto j: adjList[n]){
            if(visited[j] == -1) helper(adjList, visited, j);
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        
        for(int i=0;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>visited(V,-1);
        int ans=0;
        
        for(int i =0;i<V;i++){
            if(visited[i] == -1){
                helper(adjList, visited, i);
                ans++;
            }
        }
        
        return ans;
        
        
    }
};