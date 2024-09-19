class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right (n,0);
        for(int i=1;i<n;i++){
            if(nums[i-1]==1){
                left[i]=left[i-1]+1;
            }
        }
        for(int j=n-2;j>=0;j--){
            if(nums[j+1]==1){
                right[j]=right[j+1]+1;
            }
        }

        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,left[i]+right[i]);
        }

        return mx;
    }
};