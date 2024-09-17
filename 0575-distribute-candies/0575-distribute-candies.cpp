class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int> s;
        for(auto it: candyType) s.insert(it);
        
        if(s.size()>n/2) return n/2;
        else return s.size();
    }
};