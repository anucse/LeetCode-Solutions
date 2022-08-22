class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)
            return 0;
        
        int count =0,p=0;
        int prev_diff=nums[1]-nums[0];
        
        for(int i=1;i<n-1;i++){
            
            int curr_diff=nums[i+1]-nums[i];
            
            if(prev_diff == curr_diff)
               p++; 
            else{
                prev_diff=curr_diff;
                p=0;
            }
            
            count+=p;
        }
        
        return count;
        
    }
};