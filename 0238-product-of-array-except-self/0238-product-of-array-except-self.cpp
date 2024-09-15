class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> start(n,1);
        vector<int> end(n,1);

        start[0]=nums[0];
        end[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            start[i]=start[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            end[i]=end[i+1]*nums[i];
        }

        nums[0]=end[1];
        nums[n-1]=start[n-2];

        for(int i=1;i<n-1;i++){
            nums[i]=start[i-1]*end[i+1];
        }

        return nums;
        
    }
};