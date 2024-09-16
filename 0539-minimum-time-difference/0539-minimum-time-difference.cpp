class Solution {
public:
    int findMinDifference(vector<string> time){

	vector<int> minutes;
	int minTimeDiff=INT_MAX;

	for(auto it : time){
		int hr = stoi(it.substr(0,2));
		int min = stoi(it.substr(3));
		minutes.push_back((hr*60)+min);
    }
    sort(minutes.begin(), minutes.end());

    for(int i=0; i<minutes.size()-1; i++){
        minTimeDiff = min(minTimeDiff, minutes[i+1]-minutes[i]);
    }
  
    return min(minTimeDiff, 1440+minutes[0]-minutes[minutes.size()-1]);

    }

};