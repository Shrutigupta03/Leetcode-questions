class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1){
            return 1;
        }
        map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second%2==0){
                count+=it.second;
            }
            else{
                if(it.second>1){
                    count+=(it.second-1);
                }
            }
        }
        if(count<s.size()){
            count++;
        }
        return count;
    }
};