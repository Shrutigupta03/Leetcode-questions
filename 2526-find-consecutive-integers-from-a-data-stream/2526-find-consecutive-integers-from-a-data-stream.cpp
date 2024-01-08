#include<bits/stdc++.h>
class DataStream {
public:
    int x=0;
    int val, k;
    DataStream(int value, int k) {
        this->val=value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num!=val) x=0;
        
        if(num==val){
            x++;
        }
        if(x>=k){
            return true;
        }
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */