class Solution {
public:
    vector<int> preSmallest(vector<int> &nums){
        int n=nums.size();
        vector<int> pre(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty())
                pre[i]=-1;
            else
                pre[i]=s.top();
            s.push(i);
        }
        
        return pre;
        
    }
    
    vector<int> nextSmallest(vector<int> &nums){
        int n=nums.size();
        vector<int> next(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty())
                next[i]=n;
            else
                next[i]=s.top();
            s.push(i);
        }
        
        return next;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        vector<int> pre=preSmallest(heights);
        vector<int> next=nextSmallest(heights);
        
        for(int i=0;i<heights.size();i++){
            int curr=(next[i]-pre[i]-1)*heights[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};