class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        
        int ans =INT_MIN, p=0;
        
        for(int i : arr){
            p = p+ i;
            ans = max(ans, p);
            if(p<0) p=0;
        }
        return ans;
    }
};