class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void backtrack(int i , vector<int>& candidates, int target){
        
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(i==candidates.size())
            return ;
        if(target<0)
            return ;
        
        backtrack(i+1,candidates,target);
        temp.push_back(candidates[i]);
        backtrack(i,candidates,target-candidates[i]);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0,candidates,target);
        return ans;
    }
};