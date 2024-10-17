class Solution {
public:
    int majorityElement(vector<int>& v) {
        int el, cnt=0, n=v.size();
        
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = v[i];
            }
            else if (el == v[i]) cnt++;
            else cnt--;
        }
        
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el) cnt++;
        }
        
        if (cnt > (n / 2)) return el;
        return -1;
    }
};