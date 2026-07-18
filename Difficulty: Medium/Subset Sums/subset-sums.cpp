class Solution {
  public:
  void helper(vector<int>& arr, int n, vector<int>& res, int idx, int curr){
      if(idx == n){
          res.push_back(curr);
          return;
      }
      curr = curr + arr[idx];
      helper(arr , n, res, idx+1, curr);
      curr = curr - arr[idx];
      
      helper(arr , n, res, idx+1, curr);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>res;
        int curr =0;
        int n = arr.size();
        
        helper(arr , n , res, 0, curr);
        return res;
    }
};