class Solution {
  public:
    const int MOD = 1e9 + 7;

int helper(vector<int>& arr, vector<vector<int>>& dp, int target, int i) {
    if (i == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    if (dp[i][target] != -1) return dp[i][target];

    int nt = helper(arr, dp, target, i - 1);
    int t = 0;
    if (arr[i] <= target) {
        t = helper(arr, dp, target - arr[i], i - 1);
    }

    return dp[i][target] = (nt + t) % MOD;
}

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helper(arr, dp, target, n - 1);
}
};