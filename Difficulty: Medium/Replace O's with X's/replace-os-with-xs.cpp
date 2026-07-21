class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m= grid[0].size();
        
        queue<pair<int, int>>q;
        
        for(int i=0;i<n;i++){
            if(grid[i][0] == 'O'){
                q.push({i, 0});
                grid[i][0] = '#';
            }
            if(grid[i][m-1] == 'O'){
                q.push({i, m-1});
                grid[i][m-1] = '#';
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i] == 'O'){
                q.push({0, i});
                grid[0][i] = '#';
            }
            if(grid[n-1][i] == 'O'){
                q.push({n-1, i});
                grid[n-1][i] = '#';
            }
        }
        
        vector<int>dx={0, 0,1,-1};
        vector<int>dy={1, -1, 0, 0};
        
        while(!q.empty()){
            auto temp =q.front();
            q.pop();
            
            for(int j=0;j<4;j++){
                int nx = temp.first + dx[j];
                int ny = temp.second + dy[j];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='O'){
                    q.push({nx, ny});
                    grid[nx][ny] = '#';
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#') grid[i][j] ='O';
                else grid[i][j] = 'X';
            }
        }
    }
};