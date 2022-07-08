class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int>& temp ,int target,int i){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        
        
        
        
        for(int j=i;j<nums.size();j++){
            if(nums[j]>target)
                break;
            if(j>i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            solve(nums,temp,target-nums[j],j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,target,0);
        return ans;
    }
};