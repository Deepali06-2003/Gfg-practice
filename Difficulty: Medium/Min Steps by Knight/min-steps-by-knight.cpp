class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>>arr(n, vector<int>(n, 0));
        int sx = knightPos[0]-1;
        int sy = knightPos[1]-1;
        
        int tx = targetPos[0]-1;
        int ty = targetPos[1]-1;
        
        if(sx==tx && sy==ty) return 0;
        
        queue<pair<int, int>>q;
        int ans =0;
        q.push({sx, sy});
        arr[sx][sy]=1;
        
        vector<int>dx = {-2 , -2 , -1, 1 , 2, 2, +1, -1};
        vector<int>dy = {-1 , 1 , 2, 2, 1, -1 , -2, -2};
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto temp = q.front();
                q.pop();
                
                for(int j=0;j<8;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<n && arr[nx][ny]!=1){
                        if(nx==tx && ny==ty) return ans+1;
                        q.push({nx, ny});
                        arr[nx][ny]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};