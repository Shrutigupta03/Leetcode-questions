class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int res = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;

            while (!stk.empty() && stk.top().second > heights[i])
            {
                int idx = stk.top().first;
                int width = i - idx;
                int height = stk.top().second;
                stk.pop();

                res = max(res, height * width);
                start = idx;
            }
            
            stk.push({start, heights[i]});
        }

        while (!stk.empty())
        {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();

            res = max(res, height * width);
        }
        return res;
    }
};