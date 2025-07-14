// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>res(n);
        
        
        if(n==1) return arr[0];
        if(n==2) return max(arr[0] , arr[1]);
        
        res[0] = arr[0];
        res[1] = max(arr[0] , arr[1]);
        
        for(int i=2;i<n;i++){
            res[i] = max(res[i-1] , res[i-2]+arr[i]);
        }
        return res[n-1];
        
        
    }
};