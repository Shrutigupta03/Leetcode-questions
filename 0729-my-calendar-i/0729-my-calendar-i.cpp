class MyCalendar {
private: 
    set<pair<int,int>> st;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> event = {start, end};
        auto nextEvent = st.lower_bound(event);
        
        if(nextEvent != st.end() && nextEvent->first<end) return false;
        
        if(nextEvent != st.begin()){
            auto prevEvent = prev(nextEvent);
            
            if (prevEvent->second > start) {
                return false;
            }
        }
        
        st.insert(event);
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */