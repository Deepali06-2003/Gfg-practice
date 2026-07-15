class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>res;
        
        int n = arr.size();
        int i=0;
        while(i<n){
            int curr = arr[i]-1;
            if(i<n && arr[i]>0 && arr[i]!=arr[curr]) swap(arr[i], arr[curr]);
            else i++;
        }
        
        for(int j=0;j<n;j++){
            if(arr[j] != j+1){
                res.push_back(arr[j]);
                res.push_back(j+1);
                return res;
            }
        }
        return res;
    }
};