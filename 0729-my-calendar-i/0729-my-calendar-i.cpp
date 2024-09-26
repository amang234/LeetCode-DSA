class MyCalendar {
public:
    unordered_set<int> m; // Stores individual time points

    MyCalendar() {}

    bool book(int start, int end) {
        unordered_set<int> subset; // Temporary set to store current interval
        for (int i = start; i < end; i++) {
            if (m.count(i) > 0) { // Check if any point is already booked
                return false;
            }
            subset.insert(i);
        }
        for (auto x : subset) { // Insert current interval points into main set
            m.insert(x);
        }
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */