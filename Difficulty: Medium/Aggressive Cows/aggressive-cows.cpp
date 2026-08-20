class Solution {
  public:
  bool PlaceCows(vector<int> & arr, int k, int m){
      int prev = arr[0];
      int cow=1;
      for(int i=1;i<arr.size();i++){
          if( ((arr[i]-prev) >= m ) ){
              prev = arr[i];
              cow++;
          }
          if(cow >= k) return true;
      }
       return false;
  }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        // l and h represent the min distance
        int l = 0, h = arr[n-1]-arr[0];
        int ans=-1;
        
        while(l<=h){
            int m = (l+h)/2;
            
            if(PlaceCows(arr, k , m)){
                ans = m;
                l= m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
    }
};