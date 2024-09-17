class Solution {
public:
    string compressedString(string word) {
        string res;
        long long cnt = 1;
        for(int i=0; i<word.size(); i++){
            if(i<word.size()-1 && cnt<9 && word[i]==word[i+1]){
                cnt++;
            }
            else{
                res += to_string(cnt) + word[i];
                cnt=1;
            }
        }
        return res;
    }
};