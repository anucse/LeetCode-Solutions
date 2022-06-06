class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(128,0);
        for(auto x:s){
            freq[x]++;
        }
        int odd=0;
        for(auto x:freq){
            if(x&1)
                odd++;
        }
        if(odd>0){
            return s.size()-odd+1;
        }
        return s.size();
    }
};