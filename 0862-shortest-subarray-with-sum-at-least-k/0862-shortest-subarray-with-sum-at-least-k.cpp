class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        long long cumSum = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>> prefixSum;

        for (int i = 0; i < n; i++) {
            cumSum += nums[i];
            if (cumSum >= k) {
                res = min(res, i + 1);
            }
            while (!prefixSum.empty() && cumSum - prefixSum.top().first >= k) {
                res = min(res, i - prefixSum.top().second);
                prefixSum.pop();
            }
            prefixSum.emplace(cumSum, i);
        }

        return res == INT_MAX ? -1 : res;
    }
};