class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m;
        int i=0;
        for(int x:nums){
            m[x]=i;
            i++;
        }
        for(vector<int> x:operations){
            int prev=x[0];
            int next=x[1];
            nums[m[prev]]=next;
            m[next]=m[prev];
        }
        return nums;
    }
};