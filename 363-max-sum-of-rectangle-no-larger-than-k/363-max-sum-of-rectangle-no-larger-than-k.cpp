class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<c;i++){
            vector<int> sum(r,0);
            for(int j=i;j<c;j++){
                for(int p=0;p<r;p++){
                    sum[p]+=matrix[p][j];
                }
                set<int> s={0};
                int curr=0;
                int currMax=INT_MIN;
                for(int x:sum){
                    curr+=x;
                    auto it=s.lower_bound(curr-k);
                    if(it!=s.end())
                        currMax=max(currMax,curr-*it);
                    s.insert(curr);
                }
                ans=max(ans,currMax);
            }
        }
        return ans;
    }
};