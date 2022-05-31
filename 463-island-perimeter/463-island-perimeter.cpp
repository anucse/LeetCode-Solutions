class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;++i){
            for (int j=0;j<c;++j){
                if(grid[i][j]==1){
                    ans=ans+4;
                    if(i+1<r && grid[i+1][j])
                        ans--;
                    if(i-1>=0 && grid[i-1][j])
                        ans--;
                    if(j+1<c && grid[i][j+1])
                        ans--;
                    if(j-1>=0 && grid[i][j-1])
                        ans--;
                }
                    
                
            }
        }
        return ans;
    }
};