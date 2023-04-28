class Solution {
private:
    bool isSimilar(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) {
                    return false;
                }
            }
        }
        return count == 2 || count == 0;
    }

    void dfs(string str, vector<string>& strs, set<string>& visited) {
        if (visited.count(str) > 0) {
            return;
        }
        visited.insert(str);
        for (int i = 0; i < strs.size(); i++) {
            if (isSimilar(str, strs[i])) {
                dfs(strs[i], strs, visited);
            }
        }
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int result = 0;
        if (strs.empty()) {
            return 0;
        }
        set<string> visited;
        for (string it : strs) {
            if (visited.count(it) == 0) {
                dfs(it, strs, visited);
                result++;
            }
        }
        return result;
    }
};