class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> q;
        vector<int> vis(nums.size(), 0);
      
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int idx = q.front();
            int value = nums[idx];
            q.pop();
            if(value+idx>=nums.size()-1) return true;
            while(value){
                if(!vis[idx+value]){
                    q.push(idx+value);
                    vis[idx+value]=1;
                }
                value--;
            }
        }        
        return false;
    }
};