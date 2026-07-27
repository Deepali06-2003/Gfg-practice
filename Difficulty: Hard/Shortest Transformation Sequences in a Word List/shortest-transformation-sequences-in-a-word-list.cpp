class Solution {
  public:
    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {
        // code here
         vector<vector<string>> ans;

        unordered_set<string> st(words.begin(), words.end());

        if (st.find(e) == st.end())
            return ans;

        queue<vector<string>> q;
        q.push({s});

        st.erase(s);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> used;

            while (sz--) {
                vector<string> path = q.front();
                q.pop();

                string last = path.back();

                if (last == e) {
                    ans.push_back(path);
                    found = true;
                    continue;
                }

                for (int i = 0; i < last.size(); i++) {
                    char original = last[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        last[i] = ch;

                        if (st.find(last) != st.end()) {
                            vector<string> curr = path;
                            curr.push_back(last);
                            q.push(curr);
                            used.insert(last);
                        }
                    }

                    last[i] = original;
                }
            }

            for (auto &word : used)
                st.erase(word);
        }

        return ans;
    }
};