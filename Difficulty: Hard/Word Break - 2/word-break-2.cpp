class Solution {
  public:
  
  void helper(unordered_set<string>& st, string& s ,vector<string>& res, string curr, int idx, int n){
      if(idx == n){
          res.push_back(curr);
          return;
      }
      
      for(int len = 1;len+idx<=n; len++ ){
          string temp = s.substr(idx , len);
          if(st.find(temp) != st.end()){
              string next = curr.empty() ? temp : curr + " " + temp;

            helper(st, s, res, next, idx + len, n);
          }
      }
  }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        unordered_set<string>st;
        for(string w : dict)st.insert(w);
        
        vector<string>res;
        string curr;
        int n = s.size();
        helper(st , s, res, curr, 0, n);
        return res;
    }
};