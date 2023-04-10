class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid = (j-i)/2+i;
            int val = nums[mid];
            if(val>target){
                j=mid-1;
            }
            else if(val<target){
                i=mid+1;
            }
            else 
                return mid;
        }
        return -1;
    }
};