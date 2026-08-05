class Solution {
  public:
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m=mat[0].size();
        vector<int>src(2, -1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    src[0]=i;
                    src[1]=j;
                }
            }
        }
        
        queue<pair<int, int>>q;
        
        q.push({src[0], src[1]});
        mat[src[0]][src[1]] = 0;
        
        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1, 0, 0};
        
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                auto temp = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==2) return true;
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==3){
                        q.push({nx, ny});
                        mat[nx][ny]=0;
                    }
                }
            }
        }
        return false;
    }
};