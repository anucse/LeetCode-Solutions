class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> v;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(v.empty() || v[v.size()-1]<x){
                v.push_back(x);
            }
            
            else{
                auto it=lower_bound(v.begin(),v.end(),x);
                *it=x;
            }
        }
        
        return v.size();
    }
};