class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(mat[src[0]][src[1]]==0 || mat[dest[0]][dest[1]]==0) return -1;
        if(src == dest) return 0;
        
        queue<pair<int, int>>q;
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        
        q.push({src[0], src[1]});
        mat[src[0]][src[1]] = 0;
        
        int ans =0;
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                auto t = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nx = t.first + dx[j];
                    int ny = t.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1){
                        mat[nx][ny]=0;
                        q.push({nx, ny});
                        if((nx == dest[0]) && (ny==dest[1])) return ans+1;
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};


