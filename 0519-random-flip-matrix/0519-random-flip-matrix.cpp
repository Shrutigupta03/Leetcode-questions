class Solution {
    
    int m, n;
    map<pair<int, int>, int> mp;
    
public:
    Solution(int m, int n) {
        this -> m = m;
        this -> n = n;
    }
    
    vector<int> flip() {
        int a = rand() % m;
        int b = rand() % n;

        while(mp[{a,b}]>0)
        {
            a = rand() % m;
            b = rand() % n;
        }

        mp[{a, b}]++;
        return {a, b};
    }
    
    void reset() {
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */