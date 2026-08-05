class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int r=0, f=0;
        queue<pair<int, int>>q;
        
        int n =mat.size(), m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) f++;
                else if(mat[i][j]==2){
                    r++;
                    q.push({i, j});
                }
            }
        }
        if(f==0) return 0;
        
        vector<int>dx = {0, 0,1, -1};
        vector<int>dy = {1,-1, 0, 0};
        int ans=1;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto temp = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1){
                        f--;
                        mat[nx][ny]=2;
                        q.push({nx, ny});
                    }
                }
            }
            
            if(f==0) return ans;
            ans = ans+1;
            
        }
        if(f==0) return ans;
        return -1;
    }
};