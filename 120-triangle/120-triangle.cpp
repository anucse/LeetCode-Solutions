class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int level=n-2;level>=0;level--){
            for(int i=0;i<=level ; i++){
                triangle[level][i]+=min(triangle[level+1][i],triangle[level+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};