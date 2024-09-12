class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n==0)
            return 0;
        int ans=1;
        unordered_set<char> set;
        int left=0;
        int right=0;
        while(right<n){
            while((set.find(s[right])!=set.end() ) && left<right){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};