class Solution {
public:
    
    vector<vector<int>> ans;
    
    
    
    void solve(vector<int> &nums,vector<int> &temp, int n,int i){
    
        ans.push_back(temp);
        
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            solve(nums,temp,n,j+1);
            temp.pop_back();
            
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        vector<int> temp;
        solve(nums,temp, n,0);
        return ans;
    }
};