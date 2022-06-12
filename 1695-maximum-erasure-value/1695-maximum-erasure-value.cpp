class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int max_sum=0;
        while(r<n){
            
            sum+=nums[r];
            while(s.find(nums[r])!=s.end() && l<n){
                sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            s.insert(nums[r]);
            max_sum=max(sum,max_sum);
            r++;
        }
        return max_sum;
    }
};