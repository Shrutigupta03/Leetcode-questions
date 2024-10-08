class Solution {
public:
    int minSwaps(string s) {
        int stackSize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                stackSize++;
            else {
                if (stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};