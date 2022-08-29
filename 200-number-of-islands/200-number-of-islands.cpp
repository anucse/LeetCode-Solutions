class Solution {
public:
    void destroyIsland(vector<vector<char>>& grid,int r,int c,int i,int j){
        if(i<0||j<0||i>=r||j>=c||grid[i][j]=='0')
            return ;
        
        grid[i][j]='0';
        destroyIsland(grid,r,c,i+1,j);
        destroyIsland(grid,r,c,i-1,j);
        destroyIsland(grid,r,c,i,j+1);
        destroyIsland(grid,r,c,i,j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    destroyIsland(grid,r,c,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};