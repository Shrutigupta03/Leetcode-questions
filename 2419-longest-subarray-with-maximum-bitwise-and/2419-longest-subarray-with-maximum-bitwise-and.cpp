class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, curr = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = curr = 0;
            }

            if (maxVal == num) {
                curr++;
            } else {
                curr = 0;
            }

            ans = max(ans, curr);
        }
        return ans;
    }
};