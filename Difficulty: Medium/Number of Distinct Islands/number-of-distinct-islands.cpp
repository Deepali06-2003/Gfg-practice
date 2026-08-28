class Solution {
  public:
  
  set<vector<pair<int, int>>>st;
  
  
  void helper(vector<vector<char>>& grid, int i, int j, int n , int m, vector<pair<int, int>>& temp, int b_x, int b_y){
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='W') return;
      
      grid[i][j]='W';
      int x = i - b_x;
      int y = j - b_y;
      
      temp.push_back({x, y});
      
      helper(grid, i+1, j, n, m , temp, b_x, b_y);
      helper(grid, i-1, j, n, m , temp, b_x, b_y);
      helper(grid, i, j+1, n, m , temp, b_x, b_y);
      helper(grid, i, j-1, n, m , temp, b_x, b_y);
  }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] == 'L'){
                    vector<pair<int, int>>temp;
                    helper(grid, i, j , n , m , temp, i, j);
                    
                    if(st.find(temp) == st.end()){
                        st.insert(temp);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
