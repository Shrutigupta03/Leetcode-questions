class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1}; // Base Case

        vector<int> currentRow = {1}; // current row with 1 value in it
        vector<int> previousRow = getRow(rowIndex-1); // get the previous row

        // Now fill the current row based on previous row
        for(int i=1;i<rowIndex;i++){
            currentRow.push_back(previousRow[i-1]+previousRow[i]);
        }

        currentRow.push_back(1); // fill the last element of current row
        return currentRow;
    }
};