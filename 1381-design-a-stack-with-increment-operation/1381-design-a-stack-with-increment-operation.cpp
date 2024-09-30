class CustomStack {
private: 
    int top = -1;
    vector<int> v;
    
public:
    
    CustomStack(int maxSize) {
        v.resize(maxSize);
    }
    
    void push(int x) {
        int tempsz = v.size()-1;
        if(top<tempsz){
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