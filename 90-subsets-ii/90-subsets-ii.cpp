class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        
        int n=nums.size();
        int s=0;
        int startIndex=0;
        
        for(int i=0;i<n;i++){
            startIndex=(i>=1 && nums[i]==nums[i-1] )? s:0;
            s=ans.size();
            for(int j=startIndex;j<s;j++){
                vector<int> temp=ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};