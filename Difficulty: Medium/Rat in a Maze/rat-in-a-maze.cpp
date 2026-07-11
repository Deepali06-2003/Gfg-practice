class Solution {
  public:
  
  void helper(vector<vector<int>>& maze, int n, vector<string>& res, string curr, int i, int j){
      if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0) return;
      
      if(i == n-1 && j == n-1){
          res.push_back(curr);
          return;
      }
      maze[i][j] = 0;
      helper(maze, n, res, curr+'D', i+1, j);
      helper(maze, n, res, curr+'L', i, j-1);
      helper(maze, n, res, curr+'R', i, j+1);
      helper(maze, n, res, curr+'U', i-1, j);
      maze[i][j] =1;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        vector<string>res;
        string curr;
        
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return res;
        
        helper(maze, n , res, curr , 0, 0);
        return res;
    }
};