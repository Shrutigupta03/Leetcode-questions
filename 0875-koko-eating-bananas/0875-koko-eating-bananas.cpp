class Solution {
public:
    bool getHrs(vector<int> piles, int h, int x){
        long long res=0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%x==0)
                res += (piles[i]/x);
            else
                res += (piles[i]/x)+1;  
        }
        return res<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = *max_element(piles.begin(), piles.end());
        int mini = 1;
        
        while(mini<=maxi){
            int mid = (mini+maxi)/2;
            if(getHrs(piles, h, mid)) maxi = mid-1;
            else mini = mid+1;
        }
        return mini;
    }
};