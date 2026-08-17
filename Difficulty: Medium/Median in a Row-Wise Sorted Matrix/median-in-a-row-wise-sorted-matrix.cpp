class Solution {
  public:
  
  vector<int> merge(vector<int>& a , vector<int>& b){
      int n = a.size() , m =b.size();
      vector<int>x(n+m , 0);
      
      int i =0, j=0, k=0;
      while(i<n && j<m){
          if(a[i]<=b[j]){
              x[k] = a[i];
              i++;
          }
          else{
              x[k] = b[j];
              j++;
          }
          k++;
      }
      while(i<n){
          x[k] = a[i];
            i++; k++;
      }
      while(j<m){
          x[k] = b[j];
          j++;
          k++;
      }
      return x;
  }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size() , m = mat[0].size();
        
        vector<int>ans = mat[0];
        for(int i=1;i<n;i++){
            ans = merge(ans , mat[i]);
        }
        
        //for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
        int x= ans.size();
        return ans[x/2];
        
    }
};
