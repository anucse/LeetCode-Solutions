class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();
        int actual_sum=(n*n)*(n*n+1)/2;
        int grid_sum=0;
        int a, b;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(s.find(grid[i][j])!=s.end()){
                a=grid[i][j];
                ans.push_back(a);
            }
            else{
                s.insert(grid[i][j]);
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid_sum+=grid[i][j];
            }
        }

        b=actual_sum-grid_sum+a;
        ans.push_back(b);

        return ans;
    }
};