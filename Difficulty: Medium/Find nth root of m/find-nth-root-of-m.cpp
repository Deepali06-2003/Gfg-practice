class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        
        int l = 0, h = m;
        
        while(l<=h){
            int mid = (l+h)/2;
            
            long long value =1;
            for (int i = 0; i < n; i++) {
                value *= mid;

                if (value > m)  break;
            }
            
            if(value == m) return mid;
            else if(value > m) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
