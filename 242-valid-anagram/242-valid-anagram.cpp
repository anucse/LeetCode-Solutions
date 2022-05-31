class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        int l1=s.size();
        int l2=t.size();
        
        if(l1!=l2)
            return false;
        
        for(char x:s){
            m[x]++;
        }
        
        for(char x:t){
            m[x]--;
        }
        
        for(auto x:m){
            if(x.second != 0 )
                return false;
        }
         return true;
    }
};