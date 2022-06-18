class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1_hash(26,0),s2_hash(26,0);
        
        if(s1.size()>s2.size())
            return false;
        
        
        for(char c:s1)
            s1_hash[c-'a']++;
        
        int low=0;
        int high;
        
        for(high=0;high<s1.size();high++){
            
            s2_hash[s2[high]-'a']++;
            
        }
        
        high-=1;
        
        while(high<s2.size()){
            if(s1_hash==s2_hash)
                return true;
            
            else{
                s2_hash[s2[low]-'a']--;
                low++;

                high++;
                if(high<s2.size())
                    s2_hash[s2[high]-'a']++;
            }
            
        }
        return false;
    }
};