class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> alphabet(26,0);
        int f = 0, n = s.size();
        string ans = "";
        for(char &ch : s){
            alphabet[ch-'a']++;
            //sum++;
        }
        while(f < n)
        {
            int x;
            for(int i = 25; i >= 0; i--)
            {
                if(!alphabet[i]) continue;
                x = i;
                break;
            }
            int mx = min(repeatLimit, alphabet[x]);
            for(int j = 0; j < mx; j++){
                ans += ('a'+ x);
                alphabet[x]--;
                f++;
            }
            if(alphabet[x] == 0 || f == n) continue;
            int y = x;
            for(int i = x-1; i >= 0; i--)
            {
                if(!alphabet[i]) continue;
                x = i;
                break;
            }
            if(y == x) return ans;
            ans += ('a' + x);
            alphabet[x]--;
            f++;
        }
        return ans;
    }
};