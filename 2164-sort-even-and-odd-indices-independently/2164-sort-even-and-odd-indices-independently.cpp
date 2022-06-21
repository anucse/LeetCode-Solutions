class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n=nums.size();
        
        // sort even indices 
        int minIndex;
        
        for(int i=0;i<n;i+=2){
            minIndex=i;
            for(int j=i+2;j<n;j+=2){
                if(nums[j]<=nums[minIndex]){
                    minIndex=j;
                }
            }
            swap(nums[i],nums[minIndex]);
        }
        
        // sort odd indices 
        
        int maxIndex;
        for(int i=1;i<n;i+=2){
            maxIndex=i;
            for(int j=i+2;j<n;j+=2){
                if(nums[j]>=nums[maxIndex]){
                    maxIndex=j;
                }
            }
            swap(nums[i],nums[maxIndex]);
        }
        
        return nums;
    }
};