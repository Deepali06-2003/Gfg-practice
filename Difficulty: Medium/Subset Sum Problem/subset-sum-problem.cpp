class Solution {
  public:
  
  bool helper(vector<int>& arr, int sum, int n , int idx){
      if(sum == 0) return true;
      if(sum<0 || idx == n) return false;
      
      return helper(arr, sum-arr[idx], n , idx+1) ||  helper(arr, sum, n, idx+1);
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        //sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        return helper(arr, sum, n, 0);
    }
};