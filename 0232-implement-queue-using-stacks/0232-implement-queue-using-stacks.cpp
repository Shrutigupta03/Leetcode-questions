class MyQueue {
public:
    stack<int> st1, st2;
    int top;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.empty()) top=x;
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int popped = st2.top();
        st2.pop();
        if(!st2.empty()){
            top = st2.top();
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        return popped;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        if(st1.empty()) return true;
        return false;
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