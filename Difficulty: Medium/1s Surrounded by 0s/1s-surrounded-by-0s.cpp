class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int ones=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) ones++;
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
        
                    q.push({i, j});
                    grid[i][j] = 0;
                    ones--;
                }
            }
        }
        vector<int>dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while(!q.empty()){
            auto temp =q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nx = temp.first + dx[j];
                int ny = temp.second + dy[j];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    q.push({nx, ny});
                    ones--;
                }
            }
        }
        
        return ones;
    }
};