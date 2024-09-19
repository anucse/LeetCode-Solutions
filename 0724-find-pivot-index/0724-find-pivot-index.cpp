class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,nums[0]);
        vector<int> right(n,nums[n-1]);
        for(int i=1;i<n;i++){
            left[i]=nums[i]+left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=nums[i]+right[i+1];
        }

        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                return i;
            }
        }

        return -1;
    }
};