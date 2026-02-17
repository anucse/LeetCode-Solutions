class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int max_l=0;
        unordered_set<char> set;

        for (int r=0;r<s.length();r++){
            while (set.find(s[r])!= set.end()){
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);

            max_l= max(max_l,r-l+1);
        }

        return max_l;
    }
};