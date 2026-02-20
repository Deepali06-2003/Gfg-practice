class Solution {
  public:
  
  vector<int> topo_sort(int V , vector<int>adj[]){

	vector<int>indegree(V, 0);
	for(int i =0;i<V;i++){
		for(auto j: adj[i]){
			indegree[j]++;
		}
	}

	queue<int>q;
	for(int i =0;i<V;i++){
		if(indegree[i]==0)q.push(i);
	}
	vector<int>res;
	while(!q.empty()){
		int x = q.front();
		q.pop();

		res.push_back(x);

		for(auto j:adj[x]){
			indegree[j]--;
			if(indegree[j]==0)q.push(j);
		}
	}
	return res;
}

    string findOrder(vector<string> &words) {
        // code here
        int N = words.size();
        
        unordered_set<char> st;
        for(auto &w : words){
            for(char c : w){
                st.insert(c);
            }
        }

        
        
        vector<int>adj[26];

		for(int i=0;i<N-1;i++){

			string s1 = words[i];
			string s2 = words[i+1];
            
            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
                return "";
            
			int l = min(s1.size(), s2.size());
			for(int j=0;j<l;j++){
				
				if(s1[j]!=s2[j]){
					adj[s1[j]-'a'].push_back(s2[j]-'a');
					break;
				}

			}
		}

		vector<int>topo = topo_sort(26, adj);
		string ans ="";
		for(int i : topo){
            if(st.count(char(i + 'a')))
                ans += char(i + 'a');
        }
		if(ans.size() != st.size())
            return "";
		return ans;
	
    }
};