class Solution {
public:
    vector<vector<int>> ans;
    
    void try_(vector<int> combination, int k, int n, int start){
        if(k==combination.size()){
            if(n==0) ans.push_back(combination);
            return;
        }
        for(int i=start; i<=9; i++){
            combination.push_back(i);
            try_(combination, k, n-i, i+1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        try_(combination, k, n, 1);
        
        return ans;
    }
};