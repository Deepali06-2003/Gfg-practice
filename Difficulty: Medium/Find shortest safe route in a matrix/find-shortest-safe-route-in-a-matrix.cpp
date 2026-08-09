class Solution {
  public:
  
  void helper(vector<vector<int>> &mat, int n , int m , queue<pair<int, int>>& q){
      vector<int>dx = {0, 0, 1, -1};
      vector<int>dy = {1, -1, 0, 0};
        
        while(!q.empty()){
            
                auto temp = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]!=0){
                        mat[nx][ny]=0;
                    }
                }
        }
  }
  
    int findShortestPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>>q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i, j});
            }
        }
        helper(mat , n , m , q);
        
        
        for(int i=0;i<n;i++){
            if(mat[i][0]==1) q.push({i, 0});
            mat[i][0]=0;
        }
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        
        vector<pair<int,int>>visited;
        int ans=1;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto temp = q.front();
                q.pop();
                
                visited.clear();
                if(temp.second == m-1) return ans;
                
                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]!=0){
                        visited.push_back({nx, ny});
                        q.push({nx, ny});
                    }
                }
                
                for(int i=0;i<visited.size();i++)
                    mat[visited[i].first][visited[i].second] = 0;
            }
            ans++;
        }
        return -1;
    }
};