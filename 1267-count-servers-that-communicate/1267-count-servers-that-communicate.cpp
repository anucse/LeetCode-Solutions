class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int r,int c,int &count){
        grid[i][j]=0;
        count++;
        for(int p=0;p<c;p++){
            if(grid[i][p]==1){
                dfs(grid,i,p,r,c,count);
            }
        }
        for(int p=0;p<r;p++){
            if(grid[p][j]==1){
                dfs(grid,p,j,r,c,count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int count =0;
                if(grid[i][j]==1){
                    dfs(grid,i,j,r,c,count);
                }
                if(count>1)
                ans+=count;
            }
        }
        return ans;
    }
};