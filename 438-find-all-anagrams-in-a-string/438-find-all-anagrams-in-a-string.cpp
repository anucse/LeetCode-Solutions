class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int pLen=p.size();
        int n=s.size();
        vector<int> ans;
        
        unordered_map<char,int> pHash;
        for(char c:p){
            pHash[c]++;
        }
        
        int l=0;
        int r=0;
        unordered_map<char,int> sHash;
        while(r<pLen){
            sHash[s[r]]++;
            r++;
        }
        
        r--;
        
        while(r<n){
            if(sHash==pHash){
                ans.push_back(l);
            }
            
            r++;
            sHash[s[r]]++;
            if(sHash[s[l]]==1)
                sHash.erase(s[l]);
            else
                sHash[s[l]]--;
            l++;
            
        }
        return ans;
    }
};