class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        
        // code here  xor, index
        unordered_map<int, int>mp;
        vector<int>prefix(n, 0);
        
        int ans =0;
        
        if(arr[0] == k) ans=1;
        
        prefix[0] = arr[0];
        mp[arr[0]] = 1;
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]^arr[i];
            
            if(prefix[i] == k) ans++;
            
            if(mp.find( (prefix[i]^k) ) != mp.end() ) ans = ans +mp[prefix[i]^k] ;
            
            mp[prefix[i]]++;
        }
        //for(int i=0;i<n;i++)cout<<prefix[i]<<' ';
        
        return ans;
    }
};