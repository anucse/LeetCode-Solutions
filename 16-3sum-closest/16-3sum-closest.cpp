class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=INT_MAX;
        int sum=0;
        int ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==target)
                    return sum;
                if(sum>target)
                    k--;
                else
                    j++;
                if(diff>abs(sum-target)){
                    diff=abs(sum-target);
                    ans=sum;
                }
            }
        }
        
        return ans;
    }
};