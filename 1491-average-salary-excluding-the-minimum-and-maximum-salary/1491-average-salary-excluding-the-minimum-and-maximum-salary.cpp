class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        double avg=0;
        for(int i=1; i<n-1; i++){
            avg = avg + salary[i];
        }
        avg = avg/(n-2);
        return avg;
    }
};