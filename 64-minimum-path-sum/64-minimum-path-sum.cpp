class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<int> prev(c,0);
        vector<int> curr(c,0);
        prev[c-1]=grid[r-1][c-1];
        for(int j=c-2;j>=0;j--){
            prev[j]=prev[j+1]+grid[r-1][j];
        }
        
        for(int i=r-2;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(j==c-1)
                    curr[j]=prev[j]+grid[i][j];
                else
                    curr[j]=min(curr[j+1],prev[j])+grid[i][j];
            }
            prev=curr;
        }
        return prev[0];
    }
};