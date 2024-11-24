class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int minVal = INT_MAX;
        int neg = 0;

        for (auto row : matrix) {
            for (int x : row) {
                res += abs(x);
                if (x < 0) neg++;
                minVal = min(minVal, abs(x));
            }
        }

        if (neg % 2 != 0) res -= 2 * minVal;

        return res;
    }
};