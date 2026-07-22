class Solution {
  public:
  
  set<vector<pair<int,int>>> shapes;
  
  void dfs(vector<vector<char>>& grid, int n , int m , int i, int j, int& base_i, int& base_j , vector<pair<int,int>>& temp){
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='W') return;
      
      grid[i][j]='W';
      int coor_x = i - base_i;
      int coor_y = j - base_j;
      temp.push_back({coor_x, coor_y});
      
      dfs(grid, n, m, i+1, j, base_i, base_j, temp);
      dfs(grid, n, m, i-1, j, base_i, base_j, temp);
      dfs(grid, n, m, i, j+1, base_i, base_j, temp);
      dfs(grid, n, m, i, j-1, base_i, base_j, temp);
  }
  
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    vector<pair<int,int>> temp;
                    dfs(grid, n, m , i, j, i, j, temp);
                    
                    if(shapes.find(temp) == shapes.end()){
                       shapes.insert(temp);
                    }
                    
                }
            }
        }
        
        return shapes.size();
    }
};
