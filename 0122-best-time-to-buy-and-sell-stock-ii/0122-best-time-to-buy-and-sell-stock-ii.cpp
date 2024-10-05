class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        int mini =0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[mini]>prices[i]){
                mini = i;
            }
            else if(prices[i] > prices[mini]){
                sum += (prices[i] - prices[mini]);
                mini = i;
            }
        }
        return sum;
    }
};