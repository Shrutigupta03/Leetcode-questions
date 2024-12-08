class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int maxVal = 0;
        int ans = 0;

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;
        for(auto e: events)
        {
            while(!pq.empty() and -pq.top().first < e[0])
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            ans = max(ans, maxVal+e[2]);
            pq.push({-e[1], e[2]});
        }
        return ans;
    }
};