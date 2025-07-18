class Solution {
  public:
  void dfs(vector<vector<char>>& grid , int i , int j , int n , int m){
      if(i<0 || j<0 || i== n || j == m || grid[i][j]=='W') return ;
      
      
      grid[i][j] = 'W';
     
      
      dfs(grid , i , j+1, n , m);
       dfs(grid , i-1 , j+1, n , m);
      dfs(grid , i-1 , j, n , m);
     dfs(grid , i-1 , j-1, n , m);
       dfs(grid , i , j-1, n , m);
      dfs(grid , i+1 , j-1, n , m);
       dfs(grid , i+1 , j, n , m);
       dfs(grid , i+1 , j+1, n , m);
      
   
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 'L'){
                    dfs(grid , i , j , n , m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};