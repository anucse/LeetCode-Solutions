class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        
        double sum=0;
        double ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i>=k-1){
                ans=max(ans,sum);
                sum-=nums[start];
                start++;
            }
        }

        return ans/k;
    }
};