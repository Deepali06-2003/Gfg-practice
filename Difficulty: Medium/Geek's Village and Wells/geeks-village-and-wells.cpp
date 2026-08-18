class Solution {
  public:
    vector<vector<int>> geeksAndWells(vector<vector<char>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dp(n, vector<int>(m , INT_MAX));
        
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='W'){
                    dp[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        vector<int>dx={0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto t = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nx = t.first + dx[j];
                    int ny = t.second+ dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]==INT_MAX && mat[nx][ny] != 'N'){
                        dp[nx][ny] = dp[t.first][t.second]+1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]=='H'){
                    if(dp[i][j]==INT_MAX) dp[i][j]=-1;
                    else dp[i][j] = dp[i][j]*2;
                }
                
                else dp[i][j]=0;
            }
        }
        return dp;
    }
};




