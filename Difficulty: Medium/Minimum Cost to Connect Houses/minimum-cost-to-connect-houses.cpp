class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int V = houses.size();
        
        vector<int>dist(V, INT_MAX);
        vector<int>visited(V, 0);
        
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>>pq;
        
        pq.push({0, 0}); //dist , index
        dist[0]=0;
        
        int sum =0;
        
        while(!pq.empty()){
            
            auto temp = pq.top(); //dist , index
            pq.pop();
            
            int d = temp.first , u = temp.second;
            
            if(visited[u] == 1)continue;
            
            visited[u]=1;
            sum = sum + d;
            
            for(int i=0;i<houses.size();i++){
                if(visited[i]==0){      //not visited
                    
                    int c_d = abs(houses[u][0]-houses[i][0]) + abs(houses[u][1]-houses[i][1]);
                    
                    if(c_d < dist[i]){
                        dist[i] = c_d;
                        pq.push({dist[i] , i});
                    }
                    
                }
            }
            
        }
        return sum;
    }
};