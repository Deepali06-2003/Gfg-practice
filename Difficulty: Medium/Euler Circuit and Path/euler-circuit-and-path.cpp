class Solution {
  public:
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>deg(V, 0);
        for(int i=0;i<V;i++) deg[i] = adj[i].size();
        
        
        int odd_d=0;
        for(int i : deg){
            if(i>=0 && i%2!=0) odd_d++;
        }
        
        int start=-1;
        for(int i=0;i<V;i++){
            if(deg[i] > 0){
                start = i;
                break;
            }
        }
        
        if(start == -1) return 2;
        
        queue<int>q;
        vector<int>visited(V, -1);
        
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            for(auto j: adj[n]){
                if(visited[j]==-1){
                    visited[j]=1;
                    q.push(j);
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
             if (deg[i] > 0 && visited[i] == -1)
                return 0;
        }
        if(odd_d ==0 ) return 2;
        if( odd_d ==2 ) return 1;
        return 0;
    }
};