class Solution {
public:
    bool static compare(int a, int b){
        string s1=to_string(a);
        string s2=to_string(b);
        if((s1+s2) > (s2+s1))
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans="";
        if(nums[0]==0){
            return "0";
        }
        for(auto& x:nums){
            ans+=to_string(x);
        }

        return ans;
    }
};