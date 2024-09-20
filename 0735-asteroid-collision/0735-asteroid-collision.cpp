class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        for(int& x:nums){
            if(x>0){
                st.push(x);
                continue;
            }
            
            while(!st.empty()&& st.top()>0 && abs(st.top())<abs(x)){
                st.pop();
            }
            if(st.empty() || st.top()<0){
                st.push(x);
            }
            if(!st.empty() &&abs(x)==abs(st.top())){
                st.pop();
            }
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};