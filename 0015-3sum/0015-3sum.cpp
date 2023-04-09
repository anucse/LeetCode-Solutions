class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        
        
        for(int i=0;i<n;i++){
            
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k]+nums[i]<0){
                    j++;
                }
                else if(nums[j]+nums[k]+nums[i]>0){
                    k--;
                }
                else{
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
            
        }
        for(auto x:st){
            ans.push_back(x);
        }
        
        return ans;
    }
};