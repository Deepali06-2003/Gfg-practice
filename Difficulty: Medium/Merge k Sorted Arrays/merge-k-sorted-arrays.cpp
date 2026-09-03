class Solution {
  public:
  
  vector<int> merge(vector<int>& l1, vector<int>& l2){
      
      int n = l1.size(), m = l2.size();
      int i=0, j=0, k=0;
      
      vector<int>res(n+m);
      while(i<n && j<m){
          if(l1[i]<=l2[j]){
              res[k] = l1[i];
              i++;
          }
          else{
              res[k] = l2[j];
              j++;
          }
          k++;
      }
      
      while(i<n){
              res[k] = l1[i];
              i++;
          k++;
      }
       while(j<m){
              res[k] = l2[j];
              j++;
          k++;
      }
      
      return res;
  }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int>ans = mat[0];
        int n = mat.size();
        
        for(int i =1;i<n;i++){
            ans = merge(ans, mat[i]);
        }
        
        return ans;
    }
};