class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        double avg= accumulate(salary.begin(), salary.end(), 0) - salary[0] -                     salary[n-1];
        return avg/(n-2);
    }
};