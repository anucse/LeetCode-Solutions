class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(char c:magazine){
            m[c]++;
        }
        
        for(char c:ransomNote){
            if(m.find(c)==m.end())
                return false;
            m[c]--;
            if(m[c]==0)
                m.erase(c);
        }
        
        return true;
    }
};