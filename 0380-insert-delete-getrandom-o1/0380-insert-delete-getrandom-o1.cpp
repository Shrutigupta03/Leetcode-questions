class RandomizedSet {
public:
    vector<int> v;
    
    RandomizedSet() {
        vector<int> randset;
        this->v = randset;
    }
    
    bool insert(int val) {
        auto it = find(v.begin(), v.end(), val);
        if(it!=v.end()){
            return 0;
        }
        v.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if(find(v.begin(), v.end(), val)!=v.end()){
            v.erase(find(v.begin(), v.end(), val));
            return 1;
        }
        return 0;
    }
    
    int getRandom() {
        int x = v.size();
        int z = rand()%x;
        return v[z];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */