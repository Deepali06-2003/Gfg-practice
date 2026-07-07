class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int l =0, m =0, h = arr.size()-1;
        
        while(m<=h){
            if(arr[m]==2){
                swap(arr[h], arr[m]);
                h--;
            }
            else if(arr[m]==0){
                swap(arr[l], arr[m]);
                l++;
                m++;
            }
            else m++;
        }
    }
};