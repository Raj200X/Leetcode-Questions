class MyQueue {
public:
    int front ;
    int rear ;
    vector <int> arr;
    MyQueue() {
        front = 0;
        rear = -1;
    }
    
    void push(int x) {
        arr.push_back(x);
        rear++;
    }
    
    int pop() {
        return arr[front++];
    }
    
    int peek() {
        return arr[front];
    }
    
    bool empty() {
        if (rear<front){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */