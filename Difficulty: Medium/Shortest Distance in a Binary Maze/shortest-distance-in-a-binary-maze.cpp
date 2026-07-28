class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)return -1;
        queue<pair<int, int>>q;
        
        q.push({src[0], src[1]});
        mat[src[0]][src[1]] = 0;
        
        vector<int>dx={0, 0, 1, -1};
        vector<int>dy={ 1, -1, 0, 0};
        
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto temp = q.front();
                q.pop();
                
                if(temp.first == dest[0] && temp.second== dest[1]) return ans;
                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1){
                        q.push({nx, ny});
                        mat[nx][ny]=0;
                    }
                }
            }
            ans++;
            
        }
        return -1;
    }
};
