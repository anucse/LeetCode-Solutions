class Solution {
public:
    
    // (nums[i]+i)+(nums[j]-j)
    
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n=values.size();
        int l=values[0]+0;
        int ans=INT_MIN;
        
        for(int i=1;i<n;i++){
            ans=max(ans,l+values[i]-i);
            l=max(l,values[i]+i);
        }
        
        return ans;
    }
};