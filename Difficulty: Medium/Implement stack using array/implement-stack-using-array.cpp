class myStack {
  public:
  
  vector<int>arr;
  int size;
    int c;
    myStack(int n) {
        // Define Data Structures
        arr.resize(n);
        size =n;
        c=-1;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        if(c==-1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
         if(size-1 ==c) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(c==size-1) return;
        c++;
        arr[c] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(c==-1)return;
        arr[c]=0;
        c--;
    }

    int peek() {
        // Returns the top element of the stack
        if(c==-1) return -1;
        return arr[c];
    }
};