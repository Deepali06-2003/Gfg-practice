class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int n = a.size();
       
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>>st;
        
        vector<int>res;
       
       pq.push({a[n-1]+b[n-1] , {n-1, n-1}});
       st.insert({n-1, n-1});
       
       int sz = 0;
       
       while(!pq.empty() && sz<k){
           auto temp = pq.top();
           pq.pop();
           
           int i = temp.second.first;
           int j = temp.second.second;
           
           res.push_back(temp.first);
           sz++;
           
           if(i>0 && st.find({i-1, j}) == st.end()){
               pq.push({a[i-1]+b[j] , {i-1 , j}});
               st.insert({i-1, j});
           }
            if(j>0 && st.find({i, j-1}) == st.end()){
               pq.push({a[i]+b[j-1] , {i , j-1}});
               st.insert({i, j-1});
           }
       }
       return res;
    }
};