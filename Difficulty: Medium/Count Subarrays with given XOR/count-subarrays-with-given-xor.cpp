class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        unordered_map<int, int>mp;
        int ans = 0;
        
        if(arr[0] == k) ans =1;
        
        int c = arr[0];
        mp[c] = 1;
        
        for(int i=1;i<n;i++){
            c = c^arr[i];
            
            if(c == k) ans++;
            if(mp.find(c^k) != mp.end()) ans =ans + mp[c^k];
            
            mp[c]++;
        }
        return ans;
    }
};