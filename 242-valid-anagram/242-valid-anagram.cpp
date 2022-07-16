class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        
        for(char c:s)
            m[c]++;
        
        for(char c:t){
            if(m.find(c)==m.end())
                return false;
            if(m[c]==1)
                m.erase(c);
            else
                m[c]--;
        }
        
        if(m.empty())
            return true;
        return false;
    }
};