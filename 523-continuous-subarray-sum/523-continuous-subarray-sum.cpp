class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0 || n==1)
            return false;
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]%k == 0){
                return true;
            }
            if(mp.find(nums[i]%k)==mp.end()){
                mp[nums[i]%k]=i;
            }
            else {
                int dist=(i-(mp[nums[i]%k]));
                if (dist>=2)
                    return true;
            }
        }
        return false;
    }
};