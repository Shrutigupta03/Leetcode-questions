class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = 1;
        for(int i=0; i<sentence.size()-1; i++){
            if(i==0 && sentence.substr(i, searchWord.size()) ==  searchWord) return res;
            if(sentence[i]==' '){
                res++;
                if(sentence.substr(i+1, searchWord.size()) ==  searchWord) return res;
            }   
        }
        return -1;
    }
};