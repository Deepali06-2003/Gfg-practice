class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj_list(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj_list[u].push_back(v);
        }
        
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj_list[i].size(); j++) {
                int neighbor = adj_list[i][j];
                indegree[neighbor]++;
            }
        }
    
        
        queue<int>q;
        vector<int>res;
        
        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        
         while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    res.push_back(temp);
                    
                    //treverse adj_list for index temp.
                    
                    for(int i=0;i<adj_list[temp].size();i++){
                        indegree[adj_list[temp][i]]--;
                        if (indegree[adj_list[temp][i]] == 0) 
                            q.push(adj_list[temp][i]);
                    }
                    
        }
        
        return res;
    }
};