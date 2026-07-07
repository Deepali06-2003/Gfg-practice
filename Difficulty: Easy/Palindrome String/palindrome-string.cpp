class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int l=0, h=s.size()-1;
        while(l<=h){
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
};