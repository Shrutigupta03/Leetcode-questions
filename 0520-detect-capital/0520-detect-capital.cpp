class Solution {
public:
    bool detectCapitalUse(string word) {
        int m = word.length();
        bool flag = true;
        if(isupper(word[0])){
            if(isupper(word[1])){
                for(int i=2; i<m; i++){
                    if(!isupper(word[i]))
                        flag = false;
                }
            }
            else{
                for(int i=2; i<m; i++){
                    if(!islower(word[i]))
                        flag = false;
                }
            }
        }
        else{
            for(int i=0; i<m; i++){
                if(!islower(word[i]))
                    flag = false;
            }
        }
        return flag;
    }
};