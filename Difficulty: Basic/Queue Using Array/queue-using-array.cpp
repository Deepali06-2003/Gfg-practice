class myQueue {

  public:
  vector<int>arr;
  int f, e;
  int size;
  int c;
    myQueue(int n) {
        // Define Data Structures
        arr.resize(n);
        f=0;
        e = 0;
        size = n;
        c=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return c==0;
    }

    bool isFull() {
        // check if the queue is full
        return c==size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        arr[e] = x;
        e = (e+1)%size;
        c++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        f= (f+1)%size;
        c--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[f];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return arr[(e - 1 + size) % size];
    }
};