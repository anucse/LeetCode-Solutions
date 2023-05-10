class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n==0)
            return 0;
        
        int ans=1;
        
        unordered_map<char,int> m;
        
        int i=0;
        int j=0;
        
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>=2){
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};