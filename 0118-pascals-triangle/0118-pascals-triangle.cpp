class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector<vector<int>> ans(r);
        for(int i=0;i<r;i++){
            ans[i].resize(i+1,1);
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }

        return ans;
    }
};