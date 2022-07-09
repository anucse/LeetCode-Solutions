class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxStraightSum=INT_MIN;
        int maxSum=0;
        int minStraightSum=INT_MAX;
        int minSum=0;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum+=nums[i];
            maxStraightSum=max(maxStraightSum,maxSum);
            if(maxSum<0)
                maxSum=0;
            
            minSum+=nums[i];
            minStraightSum=min(minStraightSum,minSum);
            if(minSum>0)
                minSum=0;
           
        }
        
        if(minStraightSum==sum)
            return maxStraightSum;
        else
            return max(maxStraightSum,sum-minStraightSum);
    }
};