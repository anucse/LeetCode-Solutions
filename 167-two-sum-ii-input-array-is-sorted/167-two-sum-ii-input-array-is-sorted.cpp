class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l=0;
        int n=numbers.size();
        int r=n-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(numbers[l]+numbers[r]<target)
                l++;
            else
                r--;
        }
        
        return ans;
    }
};