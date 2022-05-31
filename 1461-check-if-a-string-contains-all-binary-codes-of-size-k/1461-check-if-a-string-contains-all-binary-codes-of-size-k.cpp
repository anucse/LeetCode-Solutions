class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())
            return false;
        unordered_set<string> all;
        for(int i=0;i<=s.size()-k;i++){
            all.insert(s.substr(i,k));
        }
        
        return (pow(2,k) == all.size());
    }
};