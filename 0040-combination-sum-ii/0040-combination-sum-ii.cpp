class Solution {
public:
    vector<vector<int>> ans;
    
    
    void solve(vector<int> &nums,vector<int> &temp,int target,int n,int i){
        
        
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(j>i && nums[j-1]==nums[j])
                continue;
            if(nums[j]>target)
                break;
            temp.push_back(nums[j]);
            solve(nums,temp,target-nums[j],n,j+1);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,target,n,0);
        return ans;
    }
};