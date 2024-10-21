class Solution {
public:
    void solve(string &s, int start, unordered_set<string> &st,
                   int curcnt, int& cnt) {

        if (curcnt + (s.size() - start) <= cnt) return;

        if (start == s.size()) {
            cnt = max(cnt, curcnt);
            return;
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            string tempstr = s.substr(start, end - start);
            if (st.find(tempstr) == st.end()) {
                st.insert(tempstr);
                solve(s, end, st, curcnt + 1, cnt);
                st.erase(tempstr);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int cnt = 0;
        solve(s, 0, st, 0, cnt);
        return cnt;
    }
};