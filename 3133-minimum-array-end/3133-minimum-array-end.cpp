class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long res=x;
        n--;
        while(n--){
            res = (res+1)|x;
        }
        return res;
    }
};