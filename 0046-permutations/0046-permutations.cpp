class Solution {
public:
    vector<int> temp;
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums,vector<bool>&freq, int n){
        
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                freq[i]=true;
                temp.push_back(nums[i]);
                solve(nums,freq,n);
                temp.pop_back();
                freq[i]=false;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<bool> freq(n,false);
        solve(nums,freq,n);
        
        
        return ans;
    }
};