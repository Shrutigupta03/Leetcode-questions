class Solution {
public:
    int maximumLength(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<string,int> m;
        int r = 0;
        while(l<s.size()){
            while(s[l]==s[r]){
                cout<<s.substr(l,r-l+1)<<endl;
                m[s.substr(l,r-l+1)]++;
                r++;
            }
            l++;
            r=l;
        }
        cout<<m.size();
        for(auto i:m){
            if(i.second >= 3 && ans < i.first.size()){
                ans = i.first.size();
            }
        }
        return ans==0?-1:ans;

    }
};