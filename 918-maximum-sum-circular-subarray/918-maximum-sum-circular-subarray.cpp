class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum=0;
        int minSum=0;
        int maxSum=0;
        int minStraightSum=INT_MAX;
        int maxStraightSum=INT_MIN;
        
        for(int x:nums){
            
            sum+=x;
            maxSum+=x;
            maxStraightSum=max(maxStraightSum,maxSum);
            if(maxSum<0)
                maxSum=0;
            
            minSum+=x;
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