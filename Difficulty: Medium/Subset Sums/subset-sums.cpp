class Solution {
  public:
  void sumOfSubset(vector<int>& arr , vector<int>& res ,int index , int curr_sum ){
      if(index == arr.size()){
          res.push_back(curr_sum);
          return;
      }
      
      
      
      //include.
      sumOfSubset(arr, res , index+1 , curr_sum+arr[index]);
      
      //exclude
      sumOfSubset(arr , res , index+1 , curr_sum);
  }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector <int> res;
        
        sumOfSubset(arr , res , 0 , 0);
            return res;
        
        
    }
};