class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        for(int i=0; i<guess.size(); i++){
            if(guess[i]==secret[i]) bull++;
        }
        map<char, int> mp1, mp2;
        for(int i=0; i<guess.size(); i++){
            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }
        int cow=0;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                cow += min(it.second, mp2[it.first]);
            }
        }
        cow = cow-bull;
        string res;
        res.append(to_string(bull));
        res.push_back('A');
        res.append(to_string(cow));
        res.push_back('B');
        
        return res;
    }
};