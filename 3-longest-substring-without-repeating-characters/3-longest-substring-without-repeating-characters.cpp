class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        unordered_set<char> st;
        int ans=0;
        
        while(r<n){
            if(st.find(s[r])==st.end()){
                int len=r-l+1;
                ans=max(ans,len);
                st.insert(s[r]);
                r++;
            }
            
            else{
                st.erase(s[l]);
                l++;
            }
        }
        
        return ans;
    }
};