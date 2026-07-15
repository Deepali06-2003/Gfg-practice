class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        unordered_map<int, int>mp;
        vector<int>prefix(n, 0);
        
        prefix[0] = arr[0];
        if(arr[0]==k) ans=1;
        mp[prefix[0]] = 0;
        
        for(int i=1;i<n;i++){
           prefix[i] = prefix[i-1] +arr[i];
           
           if (prefix[i] == k)
                ans = max(ans, i + 1);
                
           if(mp.find(prefix[i]-k) != mp.end()){
               ans = max(ans, i-mp[prefix[i]-k]);
           }
           if (mp.find(prefix[i]) == mp.end())
            mp[prefix[i]] = i;
        }
        return ans;
    }
};