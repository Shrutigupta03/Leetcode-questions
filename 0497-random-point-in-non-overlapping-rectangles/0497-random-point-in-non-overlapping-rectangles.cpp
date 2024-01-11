class Solution {
public:
    vector<vector<int>> rect;
    
    Solution(vector<vector<int>>& rects) {
        this->rect = rects;
    }
    
    vector<int> pick() {
        int n = rect.size();
        int sum_area =0;
        vector<int> res;
        
        for (auto r : rect) {
            /*
             * What we need to be aware of here is that the input may contain
             * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3, -2].
             * 
             * So, we work around it by adding +1 here. It does not affect
             * the final result of reservoir sampling.
             */
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            
            if (rand() % sum_area < area)
                res = r;
        }
        
        int x1 = rand() % (res[2] - res[0] + 1) + res[0];
        int y1 = rand() % (res[3] - res[1] + 1) + res[1];

        return {x1, y1};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */