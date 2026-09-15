class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        
        int n = arr.size(), ans=0;
        
        vector<int>dp= arr;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j])
                    dp[i] = max(dp[i] , arr[i]+dp[j]);
            }
            ans = max(ans , dp[i]);
        }
        
        return ans;
    }
};