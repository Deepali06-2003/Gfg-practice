class Solution {
  public:
  
  void helper(string& s,vector<string>& res, string curr, int start){
    if (start == s.size()) {
        res.push_back(curr);
        return;
    }
    
    //take
    curr.push_back(s[start]);
    helper(s, res, curr, start+1);
    curr.pop_back();
    
    //not take
    helper(s, res, curr, start+1);
      
  }
  
  
    vector<string> powerSet(string &s) {
        // Code here
        //sort(s.begin(), s.end());

        vector<string>res;
        string curr;
        
        helper(s, res, curr, 0);
        sort(res.begin(), res.end());
        return res;
    }
};