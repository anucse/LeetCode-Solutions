class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum_ending_here=0;
        int max_so_far=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum_ending_here=sum_ending_here+nums[i];
            max_so_far=max(max_so_far,sum_ending_here);
            if(sum_ending_here<0)
                sum_ending_here=0;
        }
        
        return max_so_far;
    }
};