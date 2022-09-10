class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=INT_MAX;
        while(s<=e){
            int m=s+(e-s)/2;
            ans=min(ans,nums[m]);
            if(nums[s]<=nums[m]){
                if(nums[m]<=nums[e]){
                    e=m-1;
                }
                else
                    s=m+1;
            }
            else{
                e=m-1;
            }
        }
        
        return ans;
    }
};