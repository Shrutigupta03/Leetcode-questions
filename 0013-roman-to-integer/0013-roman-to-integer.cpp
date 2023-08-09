class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;

    int x=0;
    for(int i=0; i<s.size(); i++){
         x+=mp[s[i]];
        if(i+1<s.size() and mp[s[i+1]]>mp[s[i]]){
            x-=2*(mp[s[i]]);
        }
    }
    return x;
    }
};