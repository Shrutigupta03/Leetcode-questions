class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        map<char,int> mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        for(int i=0;i<n-1;i++)
        {
            int x=words[i].size();
            int y=words[i+1].size();
            string p=words[i].substr(0,min(x,y));
            string q=words[i+1].substr(0,min(x,y));
            if(p==q)
            {
                if(x==max(x,y) && x!=y)
                {
                    return false;
                }
            }
            string s1=words[i];
            string s2=words[i+1];
            for(int j=0;j<min(x,y);j++)
            {
                if(mp[s1[j]]>mp[s2[j]])
                {
                    return false;
                }
                else if(mp[s1[j]]<mp[s2[j]])
                    break;
            }
        }
        return true;
    }
};