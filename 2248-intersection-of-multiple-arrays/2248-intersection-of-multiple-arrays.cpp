class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq(1001);
        vector<int> ans;
        for(vector<int> &arr:nums){
            for(int &x:arr){
                freq[x]++;
            }
        }
        for(int i=0;i<1001;i++){
            if(freq[i]==nums.size()){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};