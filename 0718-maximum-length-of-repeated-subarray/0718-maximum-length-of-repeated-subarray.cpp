class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findLength(nums2, nums1);
        vector<int> dp(n+1), prevDP(n+1);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i-1] == nums2[j-1])
                    dp[j] = prevDP[j-1] + 1;
                else dp[j] = 0;
                ans = max(ans, dp[j]);
            }
            dp.swap(prevDP);
        }
        return ans;   
    }
};