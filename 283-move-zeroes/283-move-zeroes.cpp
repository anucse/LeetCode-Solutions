class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int x:nums){
            if(x!=0){
                nums[i]=x;
                i++;
            }
        }
        
        while(i<nums.size()){
            nums[i]=0;
            i++;
        }
        
        
    }
};