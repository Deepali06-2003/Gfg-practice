class Solution {
  public:
  
  int helper(vector<int>& arr,vector<vector<int>>& dp ,int i, int j){
      
      if(i == j) return 0;
      if(dp[i][j] != -1) return dp[i][j];
      
      int min_e = INT_MAX;
      for(int k =i; k<=(j-1); k++){
            
            int step = arr[i-1] * arr[k] * arr[j];
            step += helper(arr ,dp,i , k) + helper(arr ,dp,k+1 , j);
            min_e = min(min_e , step);
        }
        
        return dp[i][j] =min_e;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        if(n<=2) return 0;
        
        vector<vector<int>>dp(n, vector<int>(n, -1));
       int ans = helper(arr , dp , 1, n-1);
        
        
        return ans;
    }
};