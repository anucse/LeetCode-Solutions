class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end()){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
            }
            else{
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};