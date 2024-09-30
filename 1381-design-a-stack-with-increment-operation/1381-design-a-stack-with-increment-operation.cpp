class CustomStack {
private:
    vector<int> stackArray;
    vector<int> incrementArray;
    int topIndex;

public:
    CustomStack(int maxSize) {
        stackArray.resize(maxSize);
        incrementArray.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex < (int)(stackArray.size()) - 1) {
            stackArray[++topIndex] = x;
        }
    }

    int pop() {
        if (topIndex < 0) return -1;
        
        int result = stackArray[topIndex] + incrementArray[topIndex];
        
        if (topIndex > 0) incrementArray[topIndex - 1] += incrementArray[topIndex];

        incrementArray[topIndex] = 0;
        topIndex--;
        return result;
    }

    void increment(int k, int val) {
        if (topIndex >= 0) {
            int incrementIndex = min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
};