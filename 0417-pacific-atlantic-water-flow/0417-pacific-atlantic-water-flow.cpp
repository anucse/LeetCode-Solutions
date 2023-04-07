class Solution {
public:
    void solve(vector<vector<int>>& grid,vector<vector<int>>& matrix,int m,int n, int i,int j){
        if(i<0 || j<0 || i>=m||j>=n||matrix[i][j]==1)
            return;
        matrix[i][j]=1;
        if(i+1<m && grid[i+1][j]>=grid[i][j])
            solve(grid,matrix,m,n,i+1,j);
        if(i-1>=0 && grid[i-1][j]>=grid[i][j])
            solve(grid,matrix,m,n,i-1,j);
        if(j+1<n && grid[i][j+1]>=grid[i][j])
            solve(grid,matrix,m,n,i,j+1);
        if(j-1>=0 && grid[i][j-1]>=grid[i][j])
            solve(grid,matrix,m,n,i,j-1);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int m =grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> pacific(m,vector<int> (n,0));
        vector<vector<int>> atlantic(m,vector<int> (n,0));
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++){
            solve(grid,pacific,m,n, i, 0);
            solve(grid,atlantic,m,n, i, n-1);
        }
        
        for(int j=0;j<n;j++){
            solve(grid,pacific,m,n, 0,j);
            solve(grid,atlantic,m,n, m-1,j);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&& atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};