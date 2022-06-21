class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product=1;
        int min_product=1;
        int ans=nums[0];
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(max_product,min_product);
            }
            max_product=max(nums[i],nums[i]*max_product);
            min_product=min(nums[i],nums[i]*min_product);
            ans=max(ans,max_product);
        }
        return ans;
    }
};