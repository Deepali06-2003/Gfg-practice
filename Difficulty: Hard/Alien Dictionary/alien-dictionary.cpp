class Solution {
  public:
  
 bool helper(string& a, string& b, vector<vector<int>>& adj){
      int len = min(a.size(), b.size());
        int i = 0;
        
        while(i < len && a[i] == b[i])
            i++;
        
        if(i == len){
            if(a.size() > b.size()) return false;
                // invalid
        }
        else{
            int u = a[i]-'a' , v = b[i]-'a';
            if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
                adj[u].push_back(v);
            }
        }
        return true;
  }
  
  
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<int>st;
        for(string word : words){
            for(char c : word){
                if(st.find(c-'a') == st.end()) st.insert(c-'a');
            }
        }
         
        vector<vector<int>>adj(26);
        for (int i = 0; i < words.size() - 1; i++) {
            if (!helper(words[i], words[i+1], adj))
                return "";
        }
        
        int V = adj.size();
        string res="";
        
        vector<int>indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto j: adj[i]) indegree[j]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0 && st.count(i)) q.push(i);
        }
        
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            res += (x+'a');
            
            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
            
        }
        
        
        if(res.size() == st.size()) return res;
        
         return "";
    }
};