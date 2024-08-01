class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0; i<details.size(); i++){
            int temp = stoi(details[i].substr(11, 2));
            if(temp>60) cnt++;
        }
        return cnt;
    }
};