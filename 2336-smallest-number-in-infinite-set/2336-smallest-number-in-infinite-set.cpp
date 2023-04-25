class SmallestInfiniteSet {
public:
    set<int> st;
    int i = 1;
    SmallestInfiniteSet() {
        st.insert(i);
    }
    
    int popSmallest() {
        int a = *st.begin();
        st.erase(a);
        i++;
        st.insert(i);
        return a;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */