class trieNode{
public:
    trieNode *child[2];
    
    trieNode(){
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};
class Solution {
   trieNode* newNode = new trieNode();
    
    void insert(int n){
        trieNode *t = newNode;
        bitset<32> bs(n);
        
        for(int j=31; j>=0; j--){
            if(!t->child[bs[j]]) t->child[bs[j]] = new trieNode();
            t = t->child[bs[j]];
        }    
    }
    
    int maxXOR(int num){
        trieNode *t = newNode;
        bitset<32> bs(num);
        int res=0;
        
        for(int j=31; j>=0; j--){
            if(t->child[!bs[j]]){
                res+=(1<<j);
                t = t->child[!bs[j]];
            }
            else
                t = t->child[bs[j]];
        } 
        return res;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for(auto n : nums) 
            insert(n);
        
        for(auto it : nums){
            ans = max(ans, maxXOR(it));
        }
        return ans;
    }
    
};