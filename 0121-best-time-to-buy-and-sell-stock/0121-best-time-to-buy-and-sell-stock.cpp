class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int index=0;
        int profit=0;
       
	   for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<prices[index])
             index=i;                                            
            if((prices[i]-prices[index])>profit)
             profit=prices[i]-prices[index];              
        } 
    return profit;
    }
};