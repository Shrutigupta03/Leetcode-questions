class NestedIterator {
public:
    vector<NestedInteger> nestedList;
    vector<int> flattenedList;
    int currentIndex = 0;

    void flatten(vector<NestedInteger>& currentList) {
        for (int i = 0; i < currentList.size(); i++) {
            if (currentList[i].isInteger()) {
                flattenedList.push_back(currentList[i].getInteger());
            } else {
                flatten(currentList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = nestedList;
        flatten(nestedList);
    }
    
    int next() {
        int num = flattenedList[currentIndex];
        currentIndex++;
        return num;
    }
    
    bool hasNext() {
        if(currentIndex<flattenedList.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */