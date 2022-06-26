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
        int i;
        for(i=0;i<len;i++){
            sum+=nums[i];
        }
        
        int l=0;
        i--;
        
        while(i<n){
            min_sum=min(sum,min_sum);
            i++;
            if(i<n){
                sum+=nums[i];
            }
            
            sum-=nums[l];
            l++;
        }
        
        return (total-min_sum);
    }
};