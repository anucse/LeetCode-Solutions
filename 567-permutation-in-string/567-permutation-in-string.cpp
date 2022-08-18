class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> s1Hash,s2Hash;
        int s1Len=s1.size();
        int s2Len=s2.size();
        
        if(s1Len>s2Len)
            return false;
        
        int l=0;
        int r=0;
        
        while(r<s1Len){
            s1Hash[s1[r]]++;
            s2Hash[s2[r]]++;
            r++;
        }
        
        r--;
        
        while(r<s2Len){
            if(s1Hash==s2Hash)
                return true;
            r++;
            s2Hash[s2[r]]++;
            if(s2Hash[s2[l]]==1)
                s2Hash.erase(s2[l]);
            else
                s2Hash[s2[l]]--;
            l++;
        }
        
        return false;
    }
};