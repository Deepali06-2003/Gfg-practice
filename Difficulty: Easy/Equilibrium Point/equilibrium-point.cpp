class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        int rs = 0;
        for(int i : arr) rs = rs+i;
        
        int ls =0;
        
        for(int i =0;i<n;i++){
            rs = rs-arr[i];
            if(rs == ls) return i;
            ls = ls+arr[i];
        }
        return -1;
    }
};