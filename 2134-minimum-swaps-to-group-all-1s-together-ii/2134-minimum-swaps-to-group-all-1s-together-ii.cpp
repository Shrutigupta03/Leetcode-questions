class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int op1 = minSwapsHelper(nums, 0);  // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1);  // Grouping all 1s together
        return min(op1, op2);
    }

private:
    int minSwapsHelper(const vector<int>& data, int val) {
        int length = data.size();
        vector<int> rightSuffixSum(length + 1, 0);

        // Construct the suffix sum array for counting opposite values
        // (val ^ 1)
        for (int i = length - 1; i >= 0; i--) {
            rightSuffixSum[i] = rightSuffixSum[i + 1];
            if (data[i] == (val ^ 1)) rightSuffixSum[i]++;
        }

        // Total zeros in the array if `val` is 1 (or vice versa)
        int totalSwapsNeeded = rightSuffixSum[0];
        // Track current number of required swaps in the current segment
        int currentSwapCount = 0;
        int minimumSwaps =
            totalSwapsNeeded - rightSuffixSum[length - totalSwapsNeeded];

        // Iterate to find the minimum swaps by sliding the potential block of
        // grouped `val`
        for (int i = 0; i < totalSwapsNeeded; i++) {
            if (data[i] == (val ^ 1)) currentSwapCount++;
            int remaining = (totalSwapsNeeded - i - 1);
            int requiredSwaps =
                ((i + 1) - currentSwapCount) +
                (remaining - rightSuffixSum[length - remaining]);
            minimumSwaps = min(minimumSwaps, requiredSwaps);
        }
        return minimumSwaps;
    }
};