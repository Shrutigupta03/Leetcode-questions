class Solution {
private:
    int i=0;
    vector<int> g;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        g.resize(n);
        for(int i=0;i<n;i++)
        {
            if(i == 0) 
            {
                g[i] =w[i];
                continue;
            }
            g[i] = g[i-1]+ w[i];
        }

    }
    
    int pickIndex() {
        int ind = rand() % g.back();
        int index = upper_bound(g.begin(), g.end(), ind) - g.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */