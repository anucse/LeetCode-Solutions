class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_set<char> st;
        
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
                maxLen=max(maxLen,(int)st.size());
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};