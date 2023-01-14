class Solution {
public:
    // function for returning parent of some node a
    int find_parent(int a, vector<int>& parents){
        if(parents[a]==a) return parents[a];
        parents[a]=find_parent(parents[a], parents);
        return parents[a];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parents(26);
        for(int i=0; i<26; i++){
            parents[i]=i;
        }
        int n = s1.size();
        for(int i=0; i<n; i++){
            int first = find_parent(s1[i]-'a', parents), second = find_parent(s2[i]-'a', parents);
            parents[max(first, second)] = min(first, second);
        }
        for(int i=0; i<baseStr.size(); i++){
            int parent = find_parent(baseStr[i]-'a', parents);
            baseStr[i] = parent+'a';
        }
        // for(int i=0; i<26; i++){
        //     char c = 'a'+parents[i];
        //     cout<<c<<" ";
        // }
        
        return baseStr;
    }
};