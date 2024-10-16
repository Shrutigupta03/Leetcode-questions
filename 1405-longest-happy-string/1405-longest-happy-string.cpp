class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        int totalItrs = a + b + c;
        string res = "";

        for (int i = 0; i < totalItrs; i++) {
            if ((a >= b and a >= c and curra != 2) or
                (a > 0 and (currb == 2 or currc == 2))) {
                res += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } 
            else if ((b >= a and b >= c and currb != 2) or
                       (b > 0 and (currc == 2 or curra == 2))) { 
                res += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } 
            else if ((c >= a and c >= b and currc != 2) or
                       (c > 0 and (curra == 2 or currb == 2))) {
                res += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return res;
    }
};