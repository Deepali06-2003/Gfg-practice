
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // code here
        
        unordered_map<int, int>mp;

        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(int i : arr){
            if((mp[i] == 1)) return i;
        }
        return 0;
    }
};
