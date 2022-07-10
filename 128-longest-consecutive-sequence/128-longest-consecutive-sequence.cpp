class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(int x:s){
            if(s.find(x-1)==s.end()){
                int y=x+1;
                while(s.find(y)!=s.end()){
                    y+=1;
                }
                ans=max(ans,(y-x));
            }
        }
        return ans;
    }
};