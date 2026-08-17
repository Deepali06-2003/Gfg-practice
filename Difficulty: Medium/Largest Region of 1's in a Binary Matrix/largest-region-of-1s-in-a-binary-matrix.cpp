class Solution {
  public:
  
  void helper(vector<vector<int>>& grid, int i, int j, int n , int m, int& curr){
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
      
      grid[i][j]=0;
      curr++;
      
      helper(grid, i+1, j, n, m, curr);
      helper(grid, i, j+1, n, m, curr);
      helper(grid, i-1, j, n, m, curr);
      helper(grid, i, j-1, n, m, curr);
      helper(grid, i-1, j-1, n, m, curr);
      helper(grid, i+1, j+1, n, m, curr);
      helper(grid, i-1, j+1, n, m, curr);
      helper(grid, i+1, j-1, n, m, curr);
  }
    int largestRegion(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    int curr=0;
                    helper(grid, i, j, n, m, curr);
                    ans = max(ans, curr);
                }
            }
        }return ans;
    }
};