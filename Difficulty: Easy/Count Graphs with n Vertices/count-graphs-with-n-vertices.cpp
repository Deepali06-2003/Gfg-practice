class Solution {
  public:
    long long count(int n) {
        // code here
        if(n<=0) return 0;
        if(n==1) return 1;
        
        long long edges = 1LL * n * (n - 1) / 2;
    return (long long)pow(2, edges);
    }
};