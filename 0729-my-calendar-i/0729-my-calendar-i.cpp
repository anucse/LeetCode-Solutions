class MyCalendar {
public:
    // Stores intervals [start, end)
    map<int, int> um;  
    MyCalendar() {
        // no need to do anything
    }
    
    bool book(int x, int y) {
        // Find the first interval with start time >= x
        auto ptr = um.lower_bound(x); // as this function returns a pointer

        // Check if this interval overlaps with [x, y)
        if(ptr != um.end()) {
            if(ptr->first < y){
                return false;  // The next interval's start time overlaps with [x, y)
            }
        }

        // Check if the previous interval overlaps with [x, y)
        if(ptr != um.begin()) {
            auto just_previous = prev(ptr);
            
            if(just_previous->second > x) {
                return false;  // The previous interval's end time overlaps with [x, y)
            }
        }

        // No overlap, so we can book this interval
        um[x] = y;
        return true;
    }
};