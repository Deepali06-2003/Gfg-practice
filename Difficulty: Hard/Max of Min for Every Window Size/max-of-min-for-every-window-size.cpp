class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        vector<int> ans(n + 1, 0);

        // Find maximum of minimums
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;

            ans[len] = max(ans[len], arr[i]);
        }

        // Fill missing window sizes
        for (int len = n - 1; len >= 1; len--) {
            ans[len] = max(ans[len], ans[len + 1]);
        }

        ans.erase(ans.begin());

        return ans;
    }
};