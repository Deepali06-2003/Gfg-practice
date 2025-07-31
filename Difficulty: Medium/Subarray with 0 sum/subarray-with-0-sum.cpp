class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int> map;
            int sum = 0;
    
            for (int num : arr) {
                sum += num;
                if (sum == 0 || map.count(sum)) {
                    return true;  
                }
                map.insert(sum);
            }
    
            return false;   
    }
};