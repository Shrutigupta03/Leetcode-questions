class Solution {
public:
    int largest(vector<int>& heights)
    {
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0; j < matrix[0].size(); j++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][j] == '1')
                {
                    mat[i][j] = (i == 0) ? 1 : mat[i - 1][j] + 1;
                }
            }
        }


        int res = INT_MIN;
        for (auto mat1: mat)
        {
            res = max(res, largest(mat1));
        }

        return res;
    }
};