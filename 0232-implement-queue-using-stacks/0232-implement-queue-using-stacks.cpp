class MyQueue {
public:
    stack<int> a;
    stack<int> b;
    MyQueue() {
        
    }
    void check(){
        if(b.size()) return;
        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        check();
        if(b.size() == 0) return -1;
        int x = b.top();
        b.pop();
        return x;
    }
    
    int peek() {
        check(); 
        if(b.size() == 0) return -1;
        return b.top();
    }
    
    bool empty() {
        check();
        return (b.size() == 0);
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