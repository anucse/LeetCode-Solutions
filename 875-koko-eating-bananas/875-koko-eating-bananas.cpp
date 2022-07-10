class Solution {
public:
    long calculate(vector<int>& nums,int k){
        long hours=0;
        for(int x:nums){
            if(x%k==0)
                hours+=(x/k);
            else
                hours+=(x/k)+1;
        }
        return hours;
    }
    
    
    
    
    int minEatingSpeed(vector<int>& nums, int h) {
        int left=1;
        int right=1000000000;
        int ans=0;
        while(left<=right){
            int k=left+(right-left)/2;
            long hours=calculate(nums,k);
            
            if(hours>h)
                left=k+1;
            else if(hours<=h){
                ans=k;
                right=k-1;
            }
        }
        return ans;
        
    }
};