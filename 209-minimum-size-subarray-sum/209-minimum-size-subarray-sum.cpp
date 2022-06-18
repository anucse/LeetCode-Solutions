class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        
        int window_size=INT_MAX;
        int window_sum=0;
        
        for(int high=0;high<n;high++){
            
            window_sum+=nums[high];
            
            while(low<=high && window_sum>=target){
                window_size=min(window_size,high-low+1);
                
                window_sum-=nums[low];
                low++;
            }
        }
        return window_size==INT_MAX?0:window_size;
    }
};