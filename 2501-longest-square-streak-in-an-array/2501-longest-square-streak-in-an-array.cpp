class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> streakLengths;

        sort(nums.begin(), nums.end());

        for (int number : nums) {
            int root = (int)sqrt(number);

            if (root * root == number &&
                streakLengths.find(root) != streakLengths.end()) {
                streakLengths[number] = streakLengths[root] + 1;
            } else {
                streakLengths[number] = 1;
            }
        }

        int longestStreak = 0;
        for (auto& [key, streakLength] : streakLengths) {
            longestStreak = max(longestStreak, streakLength);
        }

        return longestStreak == 1 ? -1 : longestStreak;
    }
};