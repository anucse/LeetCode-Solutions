class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                k--;
            }
            r++;
            if(k<0){
                if(nums[l]==0){
                    k++;
                    
                }
                l++;
            }

        }
        return r-l;
    }
};