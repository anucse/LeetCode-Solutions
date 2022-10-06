class TimeMap {
    map<int, map<string, string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        
        auto it = mp.upper_bound(timestamp);
        
        while(it-- != mp.begin())
            if(it->second.find(key) != it->second.end())
                return it->second[key];
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */