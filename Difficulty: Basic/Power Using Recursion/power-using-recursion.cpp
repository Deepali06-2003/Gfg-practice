class Solution {
  public:
  
  
    int RecursivePower(int n, int p) {
        // Code here
        
        if( p == 0) return 1;
        if(p == 1) return n;
        
        int x = RecursivePower(n, p/2);
        if(p%2 == 0) return x*x;
        return x*x*n;
    }
};
