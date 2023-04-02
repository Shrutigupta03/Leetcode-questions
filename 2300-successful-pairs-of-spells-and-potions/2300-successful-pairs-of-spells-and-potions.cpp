class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        for(int i=0; i<spells.size(); i++){
            long long x;
            int count = 0;
            // x = ceil((success*1.0)/spells[i]);
            if(success%spells[i]==0){
                x = success/spells[i];
            }
            else{
                x = (success/spells[i])+1;
            }
            // for(int j=0; j<potions.size(); j++){
            //     if(potions[j]>=x){
            //         count = potions.size()-j;
            //         break;
            //     }
            // }
            cout<<x<<" ";
            int a = lower_bound(potions.begin(), potions.end(), x)-potions.begin();
            int n = potions.size();
            int s = max(0, n-a);

            pairs.push_back(s);
        }
        return pairs;
    }
};