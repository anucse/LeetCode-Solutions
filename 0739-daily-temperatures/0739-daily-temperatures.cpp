class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        vector<int> ans;
        int n=nums.size();
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            
            if(st.size()==0){
                ans.push_back(0);
                
            }
            
            else{
                ans.push_back(st.top()-i);
            }
            
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};