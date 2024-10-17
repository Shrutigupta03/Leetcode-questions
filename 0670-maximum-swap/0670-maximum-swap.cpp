class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string k = s;
        sort(k.begin(), k.end(), greater<char>());
        int i;
        char x;
        for(i=0; i<s.size(); i++){
            if(s[i]!=k[i]){
                x = k[i];
                break;
            }
        }
        for(int j=s.size()-1; j>i; j--){
            if(s[j]==x){
                swap(s[j], s[i]);
                break;
            }
        }
        
        return stoi(s); 
    }
};