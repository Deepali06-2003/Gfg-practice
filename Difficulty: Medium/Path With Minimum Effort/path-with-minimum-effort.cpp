class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        
       priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            
            int diff = temp.first, i = temp.second.first, j = temp.second.second;
            
            if (diff > dist[i][j]) continue;
            if(i == n-1 && j== m-1) return diff;
            
            for(int x =0;x<4;x++){
                int nx = i+ dx[x];
                int ny = j+dy[x];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int curr_d = abs(mat[i][j] - mat[nx][ny]);
                    int newEffort = max(diff , curr_d);
                    
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                    
                }
            }
        }
        
        return 0;
    }
};
