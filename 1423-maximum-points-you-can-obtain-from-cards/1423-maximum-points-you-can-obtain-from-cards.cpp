class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        
        int len=n-k;
        
        //minimum subarray of size len
        
        int total=0;
        for(int x:nums){
            total+=x;
        }
        int sum=0;
        int min_sum=INT_MAX;
        int r;
        for(r=0;r<len;r++){
            sum+=nums[r];
        }
        
        int l=0;
        r--;
        
        while(r<n){
            min_sum=min(sum,min_sum);
            r++;
            if(r<n){
                sum+=nums[r];
            }
            
            sum-=nums[l];
            l++;
        }
        
        return (total-min_sum);
    }
};