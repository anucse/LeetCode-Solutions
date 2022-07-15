class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        if(s1.size()>s2.size())
            return false;
        vector<int> s1Hash(26,0),s2Hash(26,0);
        for(char c:s1){
            s1Hash[c-'a']++;
        }
        
        int l=0;
        int h;
        
        for(h=0;h<s1.size();h++){
            s2Hash[s2[h]-'a']++;
        }
        
        //h--;
        
        while(h<=n){
            if(s1Hash==s2Hash)
                return true;
            else{
                s2Hash[s2[l]-'a']--;
                l++;
                
                if(h<n)
                    s2Hash[s2[h]-'a']++;
                h++;
            }
        }
        
        return false;
    }
};