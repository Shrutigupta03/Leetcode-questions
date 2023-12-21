class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, int> mp;
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        
        for(int i = 0; i<numCourses; i++)
            if(mp[i] == 0) q.push(i);   
        
        while(size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);                     
            for(auto nextCourse : adj[cur]) 
                if(--mp[nextCourse] == 0)    
                    q.push(nextCourse);       
        }
        if(size(ans) == numCourses) return ans;             
        return {};        
    }
};