class Solution {
  public:
  int helper(vector<int> &arr, long long pages){
      int s=1;
      long long curr_s=0;
      
      for(int i=0;i<arr.size();i++){
          
          if((arr[i]+curr_s)<=pages)curr_s = arr[i]+curr_s;
          else{
              s= s+1;
              curr_s = arr[i];
          }
      }
      return s;
  }
  
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n)return -1;
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            long long mid = (low+high)/2;
            
            int ans = helper(arr, mid);
            
            if(ans > k)low = mid+1;
            else high = mid-1;
            
        }return low;
    }
};