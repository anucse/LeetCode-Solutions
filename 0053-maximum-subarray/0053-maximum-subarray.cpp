class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxi=INT_MIN;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            curr=max(curr,0);
        }
        
        return maxi;
    }
};