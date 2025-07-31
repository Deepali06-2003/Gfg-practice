class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        
            // Your code here
         unordered_map <int,int> map;
         for(int num: a){
             map[num]++;
         }
         
         for(int num : b){
             if(map[num] ==0)return false;
             map[num]--;
         }
         
        
         return true;
    }
};