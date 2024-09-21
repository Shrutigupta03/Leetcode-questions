class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string, vector<string>, greater<string>> pq;
        for(int i=0; i<n; i++){
            pq.push(to_string(i+1));
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(stoi(pq.top()));
            pq.pop();
        }
        
        return res;
    }
};