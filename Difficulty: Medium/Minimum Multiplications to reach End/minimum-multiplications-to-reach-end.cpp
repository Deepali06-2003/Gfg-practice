class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int>dist(1000, INT_MAX);
                // node, start
        queue<pair<int, int>>q;
        
        
        q.push({start, 0});
        dist[start] = 0;
        
        while(!q.empty()){
            auto j = q.front();
            q.pop();
            
            int node = j.first;
            int step = j.second;
            
            for(int i=0;i<arr.size();i++){
                int n = (node* arr[i]) % 1000;
                
                if(dist[n] > step+1){
                    dist[n] = step+1;
                    
                    if(n == end) return step+1;
                    q.push({n, dist[n]});
                }
            }
        }
        
        
        if(dist[end] == INT_MAX) return -1;
        return dist[end];
    }
};