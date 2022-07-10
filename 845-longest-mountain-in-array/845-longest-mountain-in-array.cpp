
// time : O(n) ,, space : O(1)
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        
        for(int i=1;i<n-1;i++){
            if((nums[i]>nums[i-1]) && (nums[i]>nums[i+1])){
                
                int start=i;
                int end=i;
                while(start>0 && nums[start-1]<nums[start])
                    start--;
                while(end<n-1 && nums[end]>nums[end+1])
                    end++;
                
                maxlen=max(maxlen,(end-start+1));
                i=end;
            }
        }
        return maxlen ;
    }
};