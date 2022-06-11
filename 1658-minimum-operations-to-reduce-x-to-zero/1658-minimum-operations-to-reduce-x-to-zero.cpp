class Solution {
public:
    
    /* 
    our target sum of the elements of the array is x , means we have to remove the elements that sums upto x , 
    therefore , we have to keep the elements that sums up to target=(array_sum -x ) and those elements are contiguous subarray andlength of subarray is longest possible .
    If such a subarray with target is not found then length is 0 and return -1 .
    Use sliding window method .
    */
    
    int minOperations(vector<int>& nums, int x) {
        int array_sum=0;
        int n=nums.size();
        
        for(int i : nums){
            array_sum+=i;
        }
        
        if(array_sum == x)
            return nums.size();
        
        if(array_sum<x)
            return -1;
        
        int target = array_sum-x;
        
        int l=0,r=-1;
        int len=-1;
        int curr_sum=0;
        while(r<n){
            
            if(curr_sum==target){
                len=max(len,(r-l+1));
            }
            
            curr_sum+=nums[++r];
            
            
            
            
            while (curr_sum>target && l<n){
                curr_sum-=nums[l];
                l++;
                
            }
        }
        if(len==-1)
            return -1;
        return (n-len);
    }
};