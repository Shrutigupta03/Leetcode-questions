class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> charStack;
        int deleteCount = 0;

        for (int i = 0; i < n; i++) {
            if (!charStack.empty() && charStack.top() == 'b' && s[i] == 'a') {
                charStack.pop();
                deleteCount++;
            } else {
                charStack.push(s[i]);
            }
        }

        return deleteCount;
    }
};