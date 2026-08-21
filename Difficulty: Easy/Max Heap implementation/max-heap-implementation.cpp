class maxHeap {
    stack<int>st;
  private:
  public:

    void push(int x) {
        // Insert x into the heap
        if(st.empty()) st.push(x);
        
        else if(st.top()<=x) st.push(x);
        else{
            vector<int>arr;
            while(!st.empty()){
                arr.push_back(st.top());
                st.pop();
            }
            arr.push_back(x);
            sort(arr.begin(), arr.end());
            for(int i=0;i<arr.size();i++) st.push(arr[i]);
        }
    }

    void pop() {
        // Remove the top (maximum) element
        if(st.empty()) return;
        st.pop();
    }

    int peek() {
        // Return the top element or -1 if empty
        if(st.empty()) return -1;
        int x = st.top();
        return x;
    }

    int size() {
        // Return the number of elements in the heap
        return st.size();
    }
};