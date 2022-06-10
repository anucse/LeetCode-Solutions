class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
        
        sort(nums.begin(),nums.end());
        
        if(nums[0]>0)
            return {};
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=n-1;
            int sum=0;
            while(left<right){
                sum=nums[i]+nums[left]+nums[right];
                if (sum>0)
                    right--;
                else if(sum<0)
                    left++;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int low = nums[left];
                    int high=nums[right];
                    while(left<right && low==nums[left])
                        left++;
                    while(left<right && high==nums[right])
                        right--;
                    
                   
                }
            }
            
        }
        return ans;
    }
};