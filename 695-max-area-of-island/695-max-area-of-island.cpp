class Solution {
private:
    int destroyIsland(vector<vector<int>>& grid,int r,int c,int i, int j){
        if(i<0||j<0||i>=r||j>=c||grid[i][j]!=1)
            return 0;
        grid[i][j]=0;
        
        return 1+destroyIsland(grid,r,c,i+1,j)+destroyIsland(grid,r,c,i-1,j)+destroyIsland(grid,r,c,i,j+1)+destroyIsland(grid,r,c,i,j-1);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        int count;
        int maxArea=0;
        
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j]==1){
                    count = destroyIsland(grid,r,c,i,j);
                    maxArea=max(maxArea,count);
                }
            }
        }
        
        return maxArea;
    }
};