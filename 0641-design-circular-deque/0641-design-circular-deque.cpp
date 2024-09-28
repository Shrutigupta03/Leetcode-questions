class MyCircularDeque {
public:
    
    queue<int> q;
    int n = 0;
    
    MyCircularDeque(int k) {
        this->n = k;
    }
    
    bool insertFront(int value) {
        if(q.size()<n){
           queue<int> q2;
           while(!q.empty()){
               q2.push(q.front());
               q.pop();
           }
            q.push(value);
            while(!q2.empty()){
               q.push(q2.front());
               q2.pop();
            }
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(q.size()<n){
            q.push(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!q.empty()){
            q.pop();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!q.empty()){
            queue<int> q2;
            while(q.size()>1){
                q2.push(q.front());
                q.pop();
            }
            q.pop();
            while(!q2.empty()){
               q.push(q2.front());
               q2.pop();
            }
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(!q.empty()) return q.front();
        return -1;
    }
    
    int getRear() {
        if(!q.empty()) return q.back();
        return -1;
    }
    
    bool isEmpty() {
        if(q.empty()) return true;
        return false;
    }
    
    bool isFull() {
        if(q.size()==n) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */