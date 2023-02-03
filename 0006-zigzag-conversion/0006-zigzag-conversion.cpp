class Solution {
public:

    void insert(string & ans,string & s,int start,int level,int n)
    {
        int ind=start+2*(n-level-1);
        if(ind>=s.size()|| ind<0)
         return;
        ans+=s[ind];
    }

    string convert(string s, int n) {
        int duty=n-2,cycle=n-1;
        string ans="";
        if(cycle<1)
        return s;
        
        int start;
        for(int i=0;i<=cycle;i++)
        {
            start=i;
            for(int j=start;j<s.size();j=j+2*cycle)
            {
                ans+=s[j];
                if(i%cycle)
                 insert(ans,s,j,i,n);

            }
        }

      return ans;
    }
};