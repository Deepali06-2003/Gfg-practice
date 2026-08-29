class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        
        int n = arr.size();
        if(start == end) return 0;
        
        queue<int>q;
        vector<int>visited(1000, -1);
        
        q.push(start);
        visited[start] =1;
        
        int ans=0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int z=0;z<sz;z++){
                int j = q.front();
                q.pop();
                
                for(int i=0;i<n;i++){
                    int x = (j*arr[i])%1000;
                    if(x == end) return ans+1;
                    
                    if(visited[x]==-1){
                        q.push(x);
                        visited[x]=1;
                    }
                
                }
            }
            ans++;
        }
        return -1;
    }
};