class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(vector<int> &nums,int n,int k,int i){
        
        
        
        if(k<0 || i>=n){
            bool present=find(ans.begin(),ans.end(),temp)!=ans.end();
            if(!present)
                ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[i]);
        solve(nums,n,k-1,i+1);
        temp.pop_back();
        solve(nums,n,k,i+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int k=0;k<=n;k++){
            solve(nums,n,k,0);
        }
        
        return ans;
    }
};