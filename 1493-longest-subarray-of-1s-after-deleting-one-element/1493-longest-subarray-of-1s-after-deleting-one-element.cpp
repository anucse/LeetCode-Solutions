class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                zeros++;

            }
            if(zeros>1){
                while(nums[i]!=0){
                    
                    i++;
                }
                zeros--;
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};