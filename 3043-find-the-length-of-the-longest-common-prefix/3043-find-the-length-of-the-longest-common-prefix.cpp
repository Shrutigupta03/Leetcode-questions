class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int longestPrefix = 0;
        unordered_set<string> s;

        for(int x: arr1){
            while(x){
                s.insert(to_string(x));
                x/=10;
            }
        }

        for(int y: arr2){
            while(y){
                string temp = to_string(y);
                if(s.find(temp)!=s.end() && temp.size()>longestPrefix)
                    longestPrefix = temp.size();
                y/=10;
            }
        }
    
         return longestPrefix;
    }
};

