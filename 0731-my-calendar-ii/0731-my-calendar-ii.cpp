class MyCalendarTwo {
public:
vector<pair<int, int>> events;
 vector<pair<int, int>> overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Check if there is any triple booking by looking at overlaps
        for (const auto& overlap : overlaps) {
            if (max(overlap.first, start) < min(overlap.second, end)) {
                return false; // triple booking
            }
        }
        
        // Check for any overlap and add to overlaps list if there is one
        for (const auto& event : events) {
            if (max(event.first, start) < min(event.second, end)) {
                overlaps.push_back({max(event.first, start), min(event.second, end)});
            }
        }
        
        // Add current event to events list
        events.push_back({start, end});
        
        return true; // successfully booked
    }
};





/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */