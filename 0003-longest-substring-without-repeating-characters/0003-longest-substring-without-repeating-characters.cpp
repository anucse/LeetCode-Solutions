class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> v;
        if(n==0)
            return 0;
        
        int i=0;
        int j=0;
        
        int ans=1;
        
        while(j<n){
            v[s[j]]++;
            
            
            while(v[s[j]]>=2){
                v[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
        }
        
        return ans;
    }
};