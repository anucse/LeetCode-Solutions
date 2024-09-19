class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int curr=0;
        for(int& x:nums){
            curr=curr+x;
            ans=max(ans,curr);
        }

        return ans;
    }
};