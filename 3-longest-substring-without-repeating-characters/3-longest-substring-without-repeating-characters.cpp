class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int len=0;
        
        unordered_set<int> st;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
                len = max(len,(int)st.size());
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};