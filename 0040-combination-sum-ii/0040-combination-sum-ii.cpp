class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(vector<int>& nums, int target,int n,int i){
        
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n || target<0)
            return;
        
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            if(target<nums[j])
                break;
            temp.push_back(nums[j]);
            solve(nums,target-nums[j],n,j+1);
            temp.pop_back();
            
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        solve(nums,target,n,0);
        return ans;
    }
};