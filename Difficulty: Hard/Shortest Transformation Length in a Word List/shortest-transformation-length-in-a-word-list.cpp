class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // code here
        
        unordered_set<string>st;
        for(string w : words) st.insert(w);
        
        queue<pair<string, int>>q;
        q.push({s, 1});
        
        while(!q.empty()){
            string x = q.front().first;
            int t = q.front().second;
            q.pop();
            
            if(x == e) return t;
            
            for(int i=0;i<x.size(); i++){
                char y = x[i];
                
                for(char c='a'; c<='z'; c++){
                    x[i]=c;
                    
                    if(st.find(x) != st.end()){
                        q.push({x, t+1});
                        st.erase(x);
                    }
                }
                
                x[i] = y;
            }
        }
        
        return 0;
    }
};