class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i: arr) mp[i]++;
        
        for(auto j : mp){
            if(j.second > (n/2)) return j.first;
        }
        return -1;
    }
};