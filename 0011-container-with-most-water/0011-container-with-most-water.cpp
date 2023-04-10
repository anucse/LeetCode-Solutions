class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        int j=n-1;
        int ans=0;
        
        while(i<=j){
            int area=min(nums[i],nums[j])*(j-i);
            ans=max(ans,area);
            
            int icurr=nums[i];
            int jcurr=nums[j];
            
            if(nums[i]<nums[j]){
                while(i<n && nums[i]<=icurr){
                    i++;
                }
            }
            
            else {
                while(j>=0 && nums[j]<=jcurr){
                    j--;
                }
            }
        }
        
        return ans;
        
    }
};