class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        
        int i=0;
        
        for(char c:s){
            if(m[c]==1){
                return i;
            }
            i++;
        }
        
        return -1;
    }
};