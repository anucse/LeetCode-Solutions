class Solution {
private:
    int m;
    int n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int islands=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,'*');
                    islands++;
                }
            }
        }

        return islands;

    }

    void dfs(vector<vector<char>>& grid,int i,int j,int newChar){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||grid[i][j]==newChar){
            return;
        }
        grid[i][j]=newChar;
        dfs(grid,i+1,j,newChar);
        dfs(grid,i-1,j,newChar);
        dfs(grid,i,j+1,newChar);
        dfs(grid,i,j+1,newChar);

    }
};