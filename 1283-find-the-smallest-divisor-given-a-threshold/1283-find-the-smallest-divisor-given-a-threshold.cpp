class Solution {
public:
    int calculate(vector<int>& nums,int d){
        int res=0;
        for(int x:nums){
            if(x%d==0)
                res+=(x/d);
            else
                res+=(x/d)+1;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int left=1;
        int right=1000001;
        int ans; 
        
        while(left<=right){
            int mid=left+(right-left)/2;
            int res=calculate(nums,mid);
            if(res>threshold)
                left=mid+1;
            else if(res<=threshold){
                ans=mid;
                right=mid-1;
            }
        }
        return ans;
    }
};