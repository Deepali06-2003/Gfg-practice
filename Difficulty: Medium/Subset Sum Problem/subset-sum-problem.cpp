class Solution {
  public:
  bool helper(vector<int>& arr, vector<vector<int>>& dp , int i , int sum){
      if(sum == 0)return true;
      if(i==0){
          return (arr[0] == sum);
      }
      if(dp[i][sum] != -1)return dp[i][sum];
      
      bool nt = helper(arr , dp ,i-1 , sum);
      bool t = false;
      if(arr[i] <= sum){
          t = helper(arr , dp ,i-1 , sum- arr[i]);
      }
      return dp[i][sum] = (nt | t);
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int>(sum+1 , -1));
        return helper(arr, dp , n-1 ,sum);
    }
};