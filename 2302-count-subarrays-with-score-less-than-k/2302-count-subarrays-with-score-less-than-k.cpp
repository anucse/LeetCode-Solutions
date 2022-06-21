class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int l=0;
        int r;
        long long sum=0;
        long long ans=0;
        
        for(r=0;r<n;r++){
            sum+=nums[r];
            while(sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }
            ans=ans+(r-l+1);
        }
        
        return ans;
    }
};