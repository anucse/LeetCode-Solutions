class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> m;
        int i=0;
        int j=0;
        int maxCount=0;
        int maxWindow=0;
        while(j<n){
            m[s[j]]++;
            maxCount=max(maxCount,m[s[j]]);
            while(maxCount+k<j-i+1){
                m[s[i]]--;
                i++;
            }
            maxWindow=j-i+1;
            j++;
        }
        
        return maxWindow;
    }
};