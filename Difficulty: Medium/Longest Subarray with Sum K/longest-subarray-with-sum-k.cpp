class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int>mp;
        
        int sum =0, ans=0;
        if(arr[0]==k) ans = 1;
        
        sum = sum + arr[0];
        mp[sum] = 0;
        
        for(int i=1;i<n;i++){
            sum = sum + arr[i];
            
            if(sum == k) ans = max(ans , i+1);
            if(mp.find(sum-k) != mp.end()) ans = max(ans, i-mp[sum-k]);
            
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return ans;
        
        
    }
};