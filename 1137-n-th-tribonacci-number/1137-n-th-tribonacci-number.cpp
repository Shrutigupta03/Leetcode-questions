class Solution {
public:
    int tribonacci(int n) {
       int a = 0, b = 1, c=1, d, i;
    if( n == 0)
        return a;
    if(n==1 || n==2)
        return b;
    for(i = 3; i <= n; i++)
    {
       d = a + b + c;
       a = b;
       b = c;
       c = d;
    }
    return c;
    }
};