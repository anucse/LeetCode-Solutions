class Solution {
public:
    void destroyIsland(vector<vector<char>>& grid,int i,int j,int r,int c){
        if(i<0||j<0||i>=r||j>=c||grid[i][j]=='0')
            return ;
        grid[i][j]='0';
        destroyIsland(grid,i+1,j,r,c);
        destroyIsland(grid,i,j+1,r,c);
        destroyIsland(grid,i-1,j,r,c);
        destroyIsland(grid,i,j-1,r,c);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    ans++;;
                    destroyIsland(grid,i,j,r,c);
                }
            }
        }
        return ans;
    }
};