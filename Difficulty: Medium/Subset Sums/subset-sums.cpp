class Solution {
  public:
  void solver(vector<int>& arr , vector<int>& res , int i , int curr){
       if (i == arr.size()) {
        res.push_back(curr);
        return;
    }
      
      solver(arr , res , i+1 ,curr+ arr[i]);
      solver(arr , res , i+1 , curr);
      
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        solver(arr , res, 0, 0);
        return res;
    }
};