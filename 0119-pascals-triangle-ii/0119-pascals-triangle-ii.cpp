class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans,prev;
        
        ans.push_back({1});
        prev=ans;
        
        for(int i=1;i<=n;i++){
            ans.resize(i+1,1);
            for(int j=1;j<i;j++){
                ans[j]=prev[j-1]+prev[j];
            }
            prev=ans;
        }
        
        return ans;
    }
};