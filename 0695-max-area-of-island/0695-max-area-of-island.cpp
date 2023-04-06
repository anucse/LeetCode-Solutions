class Solution {
public:
    int area;
    void solve(vector<vector<int>>& grid,int m , int n, int i, int j){
        
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0)
            return ;
        area++;
        grid[i][j]=0;
        solve(grid,m,n,i+1,j);
        solve(grid,m,n,i,j+1);
        solve(grid,m,n,i-1,j);
        solve(grid,m,n,i,j-1);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area=0;
                    solve(grid,m,n,i,j);
                    ans=max(ans,area);
                }
            }
        }
        
        return ans;
    }
};