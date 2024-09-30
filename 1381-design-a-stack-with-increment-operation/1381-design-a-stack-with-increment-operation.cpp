class CustomStack {
private: 
    int top = -1;
    vector<int> v;
    int sz=0;
    
public:
    
    CustomStack(int maxSize) {
        this->sz = maxSize;
        v.resize(sz);
    }
    
    void push(int x) {
        if(top<sz-1){
            top++;
            v[top] = x;
        }
    }
    
    int pop() {
        if(top==-1) return -1;
        int temp = v[top];
        top--;
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<v.size(); i++){
            v[i] = v[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */