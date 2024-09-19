class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        initializeBaseCases(expression, dp);

        for (int length = 3; length <= n; length++) {
            for (int start = 0; start + length - 1 < n; start++) {
                int end = start + length - 1;
                processSubexpression(expression, dp, start, end);
            }
        }

        return dp[0][n - 1];
    }

private:
    void initializeBaseCases(string& expression, vector<vector<vector<int>>>& dp) {
        int n = expression.length();

        for (int i = 0; i < n; i++) {
            if (isdigit(expression[i])) {
                int dig1 = expression[i] - '0';
                if (i + 1 < n && isdigit(expression[i + 1])) {
                    int dig2 = expression[i + 1] - '0';
                    int number = dig1 * 10 + dig2;
                    dp[i][i + 1].push_back(number);
                }
                dp[i][i].push_back(dig1);
            }
        }
    }

    void processSubexpression(string& expression, vector<vector<vector<int>>>& dp, int start, int end) {

        for (int split = start; split <= end; split++) {
            if (isdigit(expression[split])) continue;

            vector<int> leftResults = dp[start][split - 1];
            vector<int> rightResults = dp[split + 1][end];

            computeResults(expression[split], leftResults, rightResults,
                           dp[start][end]);
        }
    }

    void computeResults(char op, vector<int>& leftResults, vector<int>& rightResults, vector<int>& results) {
       
        for (int leftValue : leftResults) {
            for (int rightValue : rightResults) {
                switch (op) {
                    case '+':
                        results.push_back(leftValue + rightValue);
                        break;
                    case '-':
                        results.push_back(leftValue - rightValue);
                        break;
                    case '*':
                        results.push_back(leftValue * rightValue);
                        break;
                }
            }
        }
    }
};