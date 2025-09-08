class Solution {
  public:
  int helper(vector<vector<int>>&arr , vector<vector<int>>& dp , int d , int l_t){
      
      if(d == 0){
          int maxi =0;
          for(int i =0;i<3;i++){
              if(i != l_t){
                  maxi= max(maxi , arr[0][i]);
              }
          }
          return maxi;
      }
      
      if(dp[d][l_t] != -1)return dp[d][l_t];
      int maxi =0;
      for(int i =0;i<3;i++){
          if(i != l_t){
            int curr = arr[d][i] + helper(arr , dp , d-1 , i);
            maxi = max(maxi , curr);
          }
          
      }
      return dp[d][l_t] = maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(n , vector<int>(4 , -1));
        
        return helper(arr , dp , n-1 , 3);
    }
};