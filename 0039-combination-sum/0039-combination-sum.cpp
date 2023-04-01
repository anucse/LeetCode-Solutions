class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates,vector<int>& temp, int target,int n,int i){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i>=n)
            return;
        
        temp.push_back(candidates[i]);
        
        solve(candidates,temp,target-candidates[i],n,i);
        
        temp.pop_back();
        
        solve(candidates,temp,target,n,i+1);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        solve(candidates,temp,target,candidates.size(),0);
        return ans;
    }
};