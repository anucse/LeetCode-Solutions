class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=1 , minProduct =1 ;
        int ans=nums[0];
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                swap(maxProduct,minProduct);
            maxProduct=max(maxProduct*nums[i],nums[i]);
            minProduct=min(minProduct*nums[i],nums[i]);
            ans=max(ans,maxProduct);
        }
        
        return ans;
    }
};