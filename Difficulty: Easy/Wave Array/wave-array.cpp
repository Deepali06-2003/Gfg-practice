class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        sort(arr.begin() , arr.end());
        
        for(int i =0 ;i< arr.size(); i= i+2){
            if((i+1) < arr.size())
            swap(arr[i] , arr[i+1]);
        }
        
    }
};